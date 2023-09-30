#include "HumanB.hpp"

HumanB::HumanB(std::string const name, Weapon& weapon) : _name(name), _weapon(&weapon) {}
HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(void) {}

void	HumanB::attack(void) const {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack because he don't have weapon !" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}