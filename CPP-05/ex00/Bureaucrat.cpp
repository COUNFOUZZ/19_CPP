#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default_Bureaucrat"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& dest) {
	if (this == &dest)
		return *this;
	this->_name = dest._name;
	this->_grade = dest._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception error: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception error: Grade too low";
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::promote(void) {
	try {
		if (this->getGrade() <= 1)
			throw GradeTooHighException();
		this->_grade--;
		std::cout << "Promote: Your grade is now at " << this->getGrade() << std::endl;
	}
	catch (const GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::demote(void) {
	try {
		if (this->getGrade() >= 150)
			throw GradeTooLowException();
		this->_grade++;
		std::cout << "Demote: Your grade is now at " << this->getGrade() << std::endl;
	}
	catch (const GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", grade " << b.getGrade();
	return out;
}