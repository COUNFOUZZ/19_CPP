#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << "[Dog] Constructor" << std::endl;
}

Dog::Dog(Dog const& other) : Animal() {
    std::cout << "[Dog] Copy Constructor" << std::endl;
    *this = other;
}

Dog& Dog::operator=(Dog const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

Dog::~Dog(void) {
    std::cout << "[Dog] Destructor" << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << "Wouf" << std::endl;
}