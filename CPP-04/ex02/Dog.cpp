#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Default Dog constructor called" << std::endl;
    this->_brain = new Brain;
}

Dog::Dog(Dog const& other) : Animal(other._type) {
    std::cout << "Copy Dog constructor called" << std::endl;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*other._brain);
}

Dog::~Dog(void) {
    std::cout << "Default Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog&    Dog::operator=(Dog const& dest) {
    if (this == &dest)
        return (*this);
    this->_type = dest._type;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*dest._brain);
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << "Wouf" << std::endl;
}

void    Dog::setNewIdea(int index, std::string str) {
    this->_brain->setNewIdea(index, str);
}

void    Dog::getIdea(void) const {
    this->_brain->getIdea();
}

void    Dog::getIdea(int index) const {
    this->_brain->getIdea(index);
}