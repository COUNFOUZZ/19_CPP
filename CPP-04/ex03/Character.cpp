#include "Character.hpp"

Character::Character(void) : ICharacter(), _name("Default_Character_name") {
	for (int i = 0; i < 4; ++i)
		this->_materias[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name) {
	for (int i = 0; i < 4; ++i)
		this->_materias[i] = NULL;
}

Character::Character(Character const& other) : ICharacter() {
	*this = other;
}

Character::~Character(void) {
	for (int i = 0; i < 4; ++i) {
		if (this->_materias[i]) {
			delete	this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

Character&	Character::operator=(Character const& dest) {
	if (this == &dest)
		return *this;
	this->_name = dest._name;
	for (int i = 0; i < 4; ++i){
		if (this->_materias[i]) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
		this->_materias[i] = dest._materias[i]->clone();
	}
	return *this;
}

std::string const&	Character::getName(void) const {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full !" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Bad index, please choose an index between 0 and 3" << std::endl;
		return;
	}
	if (this->_materias[idx]) {
		this->_materias[idx] = NULL;	// memory leak
		std::cout << "Materia dropped on the ground" << std::endl;
	}
	std::cout << "There is nothing at this index" << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Bad index, please choose an index between 0 and 3" << std::endl;
		return;
	}
	if (this->_materias[idx])
		this->_materias[idx]->use(target);
}