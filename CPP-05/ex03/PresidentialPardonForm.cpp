#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", 25, 5, "Default_target") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon", 25, 5, target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm("PresidentialPardon", 25, 5, src._target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {

	this->checkForm(executor);
	std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}