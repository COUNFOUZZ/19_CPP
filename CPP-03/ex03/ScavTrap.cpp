#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "Default ScavTrap constructor called !" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap() {
    std::cout << "Copy ScavTrap constructor called !" << std::endl;
    *this = other;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap() {
    std::cout << "Name ScavTrap constructor called !" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & other) {
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage! " << std::endl;
		--_energyPoints;
	} else if (this->_hitPoints <= 0)
		std::cout << "No enough hit point to attack someone !" << std::endl;
	else
		std::cout << "No enough energy point to attack someone !" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Default ScavTrap destructor called !" << std::endl;
}

void    ScavTrap::guardGate(void) const {
    std::cout << this->_name << " enter in Gate keeper mode !" << std::endl;
}
