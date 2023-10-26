#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("_clap_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default ClapTrap constructor called !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name + "_clap_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Name ClapTrap constructor called !" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Default ClapTrap destructor called !" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & dest) {
	if (this == &dest)
		return (*this);
	this->_name = dest._name;
	this->_hitPoints = dest._hitPoints;
	this->_energyPoints = dest._energyPoints;
	this->_attackDamage = dest._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage! " << std::endl;
		--_energyPoints;
	} else if (this->_hitPoints <= 0)
		std::cout << "No enough hit point to attack someone !" << std::endl;
	else
		std::cout << "No enough energy point to attack someone !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		_hitPoints += amount;
		std::cout << "Repairs himself " << amount << std::endl;
		std::cout << "You have now " << this->_hitPoints << " hit points" << std::endl; 
		--_energyPoints;
	} else if (this->_hitPoints <= 0)
		std::cout << "No enough hit point to repair himself !" << std::endl;
	else
		std::cout << "No enough energy point to repair himself !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " take " << amount << " damage !" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}
