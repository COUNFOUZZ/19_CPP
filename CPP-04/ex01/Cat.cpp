#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << "[Cat] Constructor" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(Cat const& other) : Animal() {
    std::cout << "[Cat] Copy Constructor" << std::endl;
    *this = other;
}

Cat& Cat::operator=(Cat const& other) {
    if (this == &other)
        return (*this);
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    return (*this);
}

Cat::~Cat(void) {
    std::cout << "[Cat] Destructor" << std::endl;
    delete  this->_brain;
    this->_brain = NULL;
}

void    Cat::makeSound(void) const {
    std::cout << "Miaou" << std::endl;
}

void    Cat::createIdeasRange(int start, int end, std::string idea) {
    if (start < 0 || start > 99 || end < 0 || end > 99)
        std::cout << "You can create ideas only between 0-99" << std::endl;
    for (int i = start; i <= end; ++i)
        this->_brain->setIdeas(i, idea);
}

void    Cat::showIdeasZeroToNb(int nb) const {
    if (nb < 0 || nb > 100) {
        std::cout << "Choose how many entry of ideas you want to see (0 - 100)" << std::endl;
    }
    for (int i = 0; i < nb; ++i)
        std::cout << "[" << i << "] " << this->_brain->getIdeas(i) << std::endl;
}