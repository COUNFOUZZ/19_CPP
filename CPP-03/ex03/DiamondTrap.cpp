#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("Default_DiamondTrap") {
    std::cout << "Default DiamondTrap constructor called !" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "Copy DiamondTrap constructor called !" << std::endl;
    *this = other;
}

DiamondTrap::DiamondTrap(std::string const & name) : _name(name) {
    std::cout << "Name DiamondTrap constructor called !" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other) {
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Default DiamondTrap destructor called !" << std::endl;
}

unsigned int    DiamondTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

unsigned int    DiamondTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

unsigned int    DiamondTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

void    DiamondTrap::whoAmI(void) const {
    std::cout << "My name : " << this->_name << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}