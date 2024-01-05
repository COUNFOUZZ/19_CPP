#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern& src) { (void)src; }
Intern::~Intern(void) {}

Intern&	Intern::operator=(const Intern& other) {
	//	nothing to copy;
	(void)other;
	return *this;
}

const char*	Intern::FormDoNotExistException::what() const throw() {
	return "[Intern] Exception error: The form you have entered does not exist !";
}

AForm*	Intern::makeForm(const std::string name, std::string target) {
	std::string	form[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	int	index = -1;
	for (int i = 0; i < 3; ++i)
		if (!form[i].compare(name)) {
			index = i;
			break;
		}
	switch (index) {
		case 0:
			return	new ShrubberyCreationForm(target);
		break;
		case 1:
			return	new RobotomyRequestForm(target);
		break;
		case 2:
			return	new PresidentialPardonForm(target);
		break;
		default:
			throw FormDoNotExistException();
	}
}