#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Default_WrongAnimal") {
    std::cout << "[WrongAnimal] Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const& other) : _type(other._type) {
    std::cout << "[WrongAnimal] Copy Constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "[WrongAnimal] Destructor" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal sound" << std::endl;
}