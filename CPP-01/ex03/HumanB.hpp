#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string const	_name;
		Weapon* 			_weapon;

	public:
		HumanB(std::string const name, Weapon& weapon);
		HumanB(std::string const name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};

#endif