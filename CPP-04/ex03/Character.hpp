#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class   Character : public ICharacter {
	private:
		AMateria*	_materias[4];
		std::string	_name;

    public:
		Character(void);
		Character(std::string name);
		Character(Character const& other);
		~Character(void);

		Character&  operator=(Character const& dest);

		std::string const&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif