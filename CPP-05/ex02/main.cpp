#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void) {
	std::cout << "Shrubbery:" << std::endl;
	ShrubberyCreationForm	tree("tree");
	Bureaucrat				bob("bob", 1);

	bob.signAForm(tree);
	bob.executeForm(tree);
	std::cout << std::endl;

	std::cout << "RobotomyRequest:" << std::endl;
	RobotomyRequestForm	robot("robot1");

	bob.signAForm(robot);
	bob.executeForm(robot);
	std::cout << std::endl;

	std::cout << "PresidentialPardon:" << std::endl;
	PresidentialPardonForm	presidentForm("Bobby");

	bob.signAForm(presidentForm);
	bob.executeForm(presidentForm);
	return 0;
}