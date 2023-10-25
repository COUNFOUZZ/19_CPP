#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "Default FragTrap constructor called !" << std::endl;
    this->_name = "Default_FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & other) : ClapTrap() {
    std::cout << "Copy FragTrap constructor called !" << std::endl;
    *this = other;
}

FragTrap::FragTrap(std::string const & name) {
    std::cout << "Name FragTrap constructor called !" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap& FragTrap::operator=(FragTrap const & other) {
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

FragTrap::~FragTrap(void) {
    std::cout << "Default FragTrap destructor called !" << std::endl;
}

void    FragTrap::highFivesGuys(void) const {
    std::cout << this->_name << " ask for a high fives !" << std::endl;
}