#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {
	
	// //normal at construction
	// {
	// 	try {
	// 		Bureaucrat const bob("Bob", 10);
	// 		std::cout << bob << std::endl;

	// 		Bureaucrat const dan("Dan", 10);
	// 		std::cout << dan << std::endl;

	// 		Bureaucrat const luc("Luc", 150);
	// 		std::cout << luc << std::endl;

	// 		Bureaucrat const tib("Tib", 1);
	// 		std::cout << tib << std::endl;
	// 		std::cout << "will be print" << std::endl;
	// 	}
	// 	catch (std::exception& e){
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// std::cout << std::endl;
	// //too low at construction
	// {
	// 	try {
	// 		Bureaucrat const bob("Bob", 10);
	// 		std::cout << bob << std::endl;

	// 		Bureaucrat const dan("Dan", 10);
	// 		std::cout << dan << std::endl;

	// 		Bureaucrat const luc("Luc", 151);
	// 		std::cout << luc << std::endl;

	// 		Bureaucrat const tib("Tib", 1);
	// 		std::cout << tib << std::endl;
	// 		std::cout << "wont be print" << std::endl;
	// 	}
	// 	catch (std::exception& e){
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// std::cout << std::endl;
	// //too high at construction
	// {
	// 	try {
	// 		Bureaucrat const bob("Bob", 10);
	// 		std::cout << bob << std::endl;

	// 		Bureaucrat const dan("Dan", 10);
	// 		std::cout << dan << std::endl;

	// 		Bureaucrat const luc("Luc", 0);
	// 		std::cout << luc << std::endl;

	// 		Bureaucrat const tib("Tib", 1);
	// 		std::cout << tib << std::endl;
	// 		std::cout << "wont be print" << std::endl;
	// 	}
	// 	catch (std::exception& e){
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// std::cout << std::endl;
	
	// /*Promote and demote tests*/

	// try {
	// 	Bureaucrat bob("Bob", 10);
	// 	std::cout << bob << std::endl;
	// 	for (int i = 0; i<10; ++i){
	// 		bob.promote();
	// 		std::cout << bob << std::endl;
	// 	}
	// 	std::cout << "wont be print" << std::endl;
	// }
	// catch (std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// try {
	// 	Bureaucrat bob("Bob", 141);
	// 	std::cout << bob << std::endl;
	// 	for (int i = 0; i<10; ++i){
	// 		bob.demote();
	// 		std::cout << bob << std::endl;
	// 	}
	// 	std::cout << "wont be print" << std::endl;
	// }
	// catch (std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	AForm a("a", 1, 150);
	// 	std::cout << a << std::endl;
	// }
	// catch (std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }

	{
		Bureaucrat bob("Bob", 16);
		AForm	war("war declaration", 15, 5);

		bob.signAForm(war);
	}
	{
		Bureaucrat bob("Bob", 1);
		AForm	war("war declaration", 15, 5);

		bob.signAForm(war);
	}
	return 0;
}