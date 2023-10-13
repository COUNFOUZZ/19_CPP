#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "Default ScavTrap constructor called !" << std::endl;
    this->_name = "Default_ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap() {
    std::cout << "Copy ScavTrap constructor called !" << std::endl;
    *this = other;
}

ScavTrap::ScavTrap(std::string const & name) {
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

ScavTrap::~ScavTrap(void) {
    std::cout << "Default ScavTrap destructor called !" << std::endl;
}

void    ScavTrap::guardGate(void) const {
    std::cout << this->_name << " enter in Gate keeper mode !" << std::endl;
}