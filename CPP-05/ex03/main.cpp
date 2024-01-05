#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	try {
		Intern	intern;
		AForm*	form;

		std::cout << "Shrubbery:" << std::endl;
		Bureaucrat	bob("bob", 1);

		form = intern.makeForm("ShrubberyCreationForm", "tree");
		bob.signAForm(*form);
		bob.executeForm(*form);
		delete form;
		std::cout << std::endl;

		std::cout << "RobotomyRequest:" << std::endl;
		form = intern.makeForm("RobotomyRequestForm", "Blender");
		bob.signAForm(*form);
		bob.executeForm(*form);
		delete form;
		std::cout << std::endl;

		std::cout << "PresidentialPardon:" << std::endl;
		form = intern.makeForm("PresidentialPardonForm", "Bobby");
		bob.signAForm(*form);
		bob.executeForm(*form);
		delete form;
		std::cout << std::endl;

		//	Error intern
		std::cout << "Error:" << std::endl;
		form = intern.makeForm("Test", "hello");
		bob.signAForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}