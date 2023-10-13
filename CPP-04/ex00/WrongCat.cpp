#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    std::cout << "[WrongCat] Constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal() {
    std::cout << "[WrongCat] Copy Constructor" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(WrongCat const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

WrongCat::~WrongCat(void) {
    std::cout << "[WrongCat] Destructor" << std::endl;
}

void    WrongCat::makeSound(void) const {
    std::cout << "Miaou" << std::endl;
}