#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) : _type(other._type) {
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const& type) : _type(type) {
    std::cout << "Type WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}

WrongAnimal&    WrongAnimal::operator=(WrongAnimal const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    return (*this);
}

std::string WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "I'm just a WrongAnimal" << std::endl;
}