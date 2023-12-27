#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource() {
	for (int i = 0; i < 4; ++i)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& dest) : IMateriaSource() {
	*this = dest;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; ++i) {
		if (this->_materias[i]) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& dest) {
	if (this == &dest)
		return *this;
	for (int i = 0; i < 4; ++i) {
		if (this->_materias[i]) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
		this->_materias[i] = dest._materias[i]->clone();
	}
	return *this;	
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full !" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	return 0;
}