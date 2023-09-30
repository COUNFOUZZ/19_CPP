#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {return;}
Zombie::Zombie(void) : _name("Default") {return;}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
	return;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
	return;
}
