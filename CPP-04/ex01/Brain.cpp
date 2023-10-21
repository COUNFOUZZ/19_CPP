#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "[Brain] Constructor" << std::endl;
}

Brain::Brain(Brain const& other) {
    std::cout << "[Brain] Copy Constructor" << std::endl;
    *this = other;
}

Brain& Brain::operator=(Brain const& other) {
    if (this == &other)
        return (*this);
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = other._ideas[i];
    return (*this);
}

Brain::~Brain(void) {
    std::cout << "[Brain] Destructor" << std::endl;
}

std::string Brain::getIdeas(int index) const {
    if (index < 0 || index > 99)
        return ("Bad index, choose between 0 - 99");
    return (this->_ideas[index]);
}

void    Brain::setIdeas(int index, std::string const ideas) {
    if (index >= 0 && index <= 99)
        this->_ideas[index] = ideas;
}