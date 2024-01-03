#include "Form.hpp"

Form::Form(void) : _name("Default_Form"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}
Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooHighException();
}
Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}
Form::~Form(void) {}

Form&	Form::operator=(const Form& dest) {
	if (this == &dest)
		return *this;
	this->_signed = dest._signed;
	return *this;
}

std::string	Form::getName(void) const {
	return this->_name;
}

bool	Form::getSigned(void) const {
	return this->_signed;
}

int	Form::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int	Form::getGradeToExecute(void) const {
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "[Form] Exception error: Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "[Form] Exception error: Grade too low";
}

std::ostream&	operator<<(std::ostream& out, const Form& b) {
	out << "Name: " << b.getName() << std::endl
	<< "Is signed: " << b.getSigned() << std::endl
	<< "Grade required to sign: " << b.getGradeToSign() << std::endl
	<< "Grade required to execute: " << b.getGradeToExecute();
	return out;
}