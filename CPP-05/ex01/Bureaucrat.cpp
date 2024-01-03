#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default_Bureaucrat"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& dest) {
	if (this == &dest)
		return *this;
	this->_grade = dest._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "[Bureaucrat] Exception error: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "[Bureaucrat] Exception error: Grade too low";
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::promote(void) {
	if (this->getGrade() <= 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "Promote: Your grade is now at " << this->getGrade() << std::endl;
}

void	Bureaucrat::demote(void) {
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Demote: Your grade is now at " << this->getGrade() << std::endl;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", grade " << b.getGrade();
	return out;
}