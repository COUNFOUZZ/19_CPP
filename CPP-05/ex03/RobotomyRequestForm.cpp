#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45, "Default_target") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest", 72, 45, target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm("RobotomyRequest", 72, 45, src._target) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->checkForm(executor);
	std::cout << "Makes some drilling noises. Then, informs that " << this->_target << " has been robotomized successfully 50%% of the time. Otherwise, informs that the robotomy failed." << std::endl;
}