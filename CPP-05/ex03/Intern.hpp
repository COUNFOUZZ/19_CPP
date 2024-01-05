#ifndef	INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		class FormDoNotExistException : public std::exception {
			public:
				const char* what() const throw();
		};
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern(void);

		Intern&	operator=(const Intern& other);

		AForm*	makeForm(const std::string name, const std::string target);
};

#endif