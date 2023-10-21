#include "Animal.hpp"

Animal::Animal(void) : _type("Default_Animal") {
    std::cout << "[Animal] Constructor" << std::endl;
}
Animal::Animal(Animal const& other) : _type(other._type) {
    std::cout << "[Animal] Copy Constructor" << std::endl;
}

Animal& Animal::operator=(Animal const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

Animal::~Animal(void) {
    std::cout << "[Animal] Destructor" << std::endl;
}

std::string Animal::getType(void) const {
    return (this->_type);
}

void    Animal::makeSound(void) const {
    std::cout << "Animal sound" << std::endl;
}