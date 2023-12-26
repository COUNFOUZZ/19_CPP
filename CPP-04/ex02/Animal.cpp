#include "Animal.hpp"

Animal::Animal(void) : _type("Default_Animal_Type") {
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const& other) : _type(other._type) {
    std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::Animal(std::string const type) : _type(type) {
    std::cout << "Type Animal constructor called" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Default Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    return (*this);
}

std::string	Animal::getType(void) const {
	return this->_type;
}