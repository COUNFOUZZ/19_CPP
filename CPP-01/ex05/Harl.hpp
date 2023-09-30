#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	private:
		void	(Harl::*_ftPtr[4]) (void) const;
		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level) const;
};

#endif