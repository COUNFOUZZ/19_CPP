#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Default_AMaterial_type") {}
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(AMateria const& other) : _type(other._type) {}
AMateria::~AMateria(void) {}

AMateria&   AMateria::operator=(AMateria const& dest) {
    if (this == &dest)
        return *this;
    this->_type = dest._type;
    return *this;
}

std::string const&  AMateria::getType(void) const {
    return this->_type;
}

void    AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "I'm not supposed to be called" << std::endl;
}