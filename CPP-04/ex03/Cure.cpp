#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure") {}
Cure::Cure(Cure const& other) : AMateria(other._type) {}
Cure::~Cure(void) {}

Cure&	Cure::operator=(Cure const& dest) {
	if (this == &dest)
		return *this;
	this->_type = dest._type;
	return *this;
}

AMateria*	Cure::clone(void) const {
	return new Cure();
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}