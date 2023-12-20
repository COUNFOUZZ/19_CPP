#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
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

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
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

void	FragTrap::attack(const std::string& target) {
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage! " << std::endl;
		--_energyPoints;
	} else if (this->_hitPoints <= 0)
		std::cout << "No enough hit point to attack someone !" << std::endl;
	else
		std::cout << "No enough energy point to attack someone !" << std::endl;
}

void    FragTrap::highFivesGuys(void) const {
    std::cout << this->_name << " ask for a high fives !" << std::endl;
}