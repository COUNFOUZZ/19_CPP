#include "./Weapon.hpp"

Weapon::Weapon(void) {}
Weapon::Weapon(std::string name) : _type(name) {}
Weapon::~Weapon(void) {}

std::string const &	Weapon::getType(void) const {
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}