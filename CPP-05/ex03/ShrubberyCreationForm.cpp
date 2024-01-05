#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137, "Default_shrubbery") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137, target + "_shrubbery") {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("Shruberry", 145, 137, src._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->checkForm(executor);
	std::ofstream	out(this->_target);

	if (!out.is_open())
		throw FileNotOpenException();
	out << "    _\\/_" << std::endl;
	out << "     /\\" << std::endl;
	out << "     /\\" << std::endl;
	out << "    /  \\" << std::endl;
	out << "    /~~\\o" << std::endl;
	out << "   /o   \\" << std::endl;
	out << "  /~~*~~~\\" << std::endl;
	out << " o/    o \\" << std::endl;
	out << " /~~~~~~~~\\~`" << std::endl;
	out << "/__*_______\\" << std::endl;
	out << "     ||" << std::endl;
	out << "   \\====/" << std::endl;
	out << "    \\__/" << std::endl;
	out.close();
}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "[Shrubbery] Exception error: Impossible to open the file !";
}