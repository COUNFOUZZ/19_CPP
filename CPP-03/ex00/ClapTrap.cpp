#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

}

ClapTrap::~ClapTrap(void) {}

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
		std::cout << "No enough hit point to attack someone !" << std::endl;
	else
		std::cout << "No enough energy point to attack someone !" << std::endl;
}

