#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << "[Cat] Constructor" << std::endl;
}

Cat::Cat(Cat const& other) : Animal() {
    std::cout << "[Cat] Copy Constructor" << std::endl;
    *this = other;
}

Cat& Cat::operator=(Cat const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

Cat::~Cat(void) {
    std::cout << "[Cat] Destructor" << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << "Miaou" << std::endl;
}