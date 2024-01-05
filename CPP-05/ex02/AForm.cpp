#include "AForm.hpp"

AForm::AForm(void) : _target("Default"), _name("Default_AForm"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}
AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target) : _target(target), _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooHighException();
}
AForm::AForm(const AForm& src) : _target(src._target), _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}
AForm::~AForm(void) {}

AForm&	AForm::operator=(const AForm& dest) {
	if (this == &dest)
		return *this;
	this->_signed = dest._signed;
	this->_target = dest._target;
	return *this;
}

std::string	AForm::getName(void) const {
	return this->_name;
}

bool	AForm::getSigned(void) const {
	return this->_signed;
}

int	AForm::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExecute(void) const {
	return this->_gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "[AForm] Exception error: Grade too high !";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "[AForm] Exception error: Grade too low !";
}

const char*	AForm::NotSignedException::what() const throw() {
	return "[AForm] Exception error: Form not signed !";
}

std::ostream&	operator<<(std::ostream& out, const AForm& b) {
	out << "Name: " << b.getName() << std::endl
	<< "Is signed: " << b.getSigned() << std::endl
	<< "Grade required to sign: " << b.getGradeToSign() << std::endl
	<< "Grade required to execute: " << b.getGradeToExecute();
	return out;
}

void	AForm::checkForm(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else if (!this->getSigned())
		throw NotSignedException();
}