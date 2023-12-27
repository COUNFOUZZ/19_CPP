#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(Ice const& other) : AMateria(other._type) {}
Ice::~Ice(void) {}

Ice&	Ice::operator=(Ice const& dest) {
	if (this == &dest)
		return *this;
	this->_type = dest._type;
	return *this;
}

AMateria*	Ice::clone(void) const {
	return new Ice();
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}