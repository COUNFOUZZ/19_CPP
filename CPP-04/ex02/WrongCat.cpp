#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat") {
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other._type) {
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat&   WrongCat::operator=(WrongCat const& dest) {
    if (this == &dest)
        return *this;
    this->_type = dest._type;
    return *this;
}

void    WrongCat::makeSound(void) const {
    std::cout << "WrongCat miaou" << std::endl;
}