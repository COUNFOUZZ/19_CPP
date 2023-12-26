#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(Brain const& other) {
    std::cout << "Copy Brain constructor called" << std::endl;
    *this = other;
}

Brain::~Brain(void) {
    std::cout << "Default Brain destructor called" << std::endl;
}

Brain&  Brain::operator=(Brain const& dest) {
    if (this == &dest)
        return *this;
    for(int i = 0; i < 100; ++i)
        this->_ideas[i] = dest._ideas[i];
    return *this;
}

void    Brain::setNewIdea(int index, std::string str) {
    if (index < 0 || index >= 100) {
        std::cout << "Bad index, please choose an index between 0 and 99" << std::endl;
        return;
    }
    std::cout << "I have a new idea !" << std::endl;
    this->_ideas[index] = str;
}

void    Brain::getIdea(void) const {
    for(int i = 0; i < 100; ++i)
        std::cout << i << ". " << this->_ideas[i] << std::endl;
}

void    Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cout << "Bad index, please choose an index between 0 and 99" << std::endl;
        return;
    }
    std::cout << index << ". " << this->_ideas[index] << std::endl;
}