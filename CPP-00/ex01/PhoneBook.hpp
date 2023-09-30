#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook {
	private:
		int		_index;
		Contact	_contact[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void) const;
};

#endif