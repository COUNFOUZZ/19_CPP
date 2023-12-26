#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other._type) {
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat&    Cat::operator=(Cat const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << "Miaou" << std::endl;
}