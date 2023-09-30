#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		int			_index;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkSecret;
		void		_askInfos(std::string& info, std::string const title);
		std::string	_limit10char(std::string info) const;

	public:
		Contact(void);
		~Contact(void);
		void	newContact(int index);
		void	showMinimalist(void) const;
		void	showFull(void) const;
		int		exist(void) const;
};

#endif