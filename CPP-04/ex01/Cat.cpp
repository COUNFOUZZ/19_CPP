#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Default Cat constructor called" << std::endl;
    this->_brain = new Brain;
}

Cat::Cat(Cat const& other) : Animal(), _brain(NULL) {
    std::cout << "Copy Cat constructor called" << std::endl;
    *this = other;
}

Cat::~Cat(void) {
    std::cout << "Default Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat&    Cat::operator=(Cat const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*dest._brain);
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << "Miaou" << std::endl;
}

void    Cat::setNewIdea(int index, std::string str) {
    this->_brain->setNewIdea(index, str);
}

void    Cat::getIdea(void) const {
    this->_brain->getIdea();
}

void    Cat::getIdea(int index) const {
    this->_brain->getIdea(index);
}