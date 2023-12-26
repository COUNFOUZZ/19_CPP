#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other._type) {
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog&    Dog::operator=(Dog const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << "Wouf" << std::endl;
}