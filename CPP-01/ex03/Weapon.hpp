#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(std::string name);
		~Weapon(void);
		std::string const &	getType(void) const;
		void				setType(std::string type);
};

#endif