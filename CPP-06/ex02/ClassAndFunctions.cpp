#include "ClassAndFunctions.hpp"

Base*	generate(void) {
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			std::cerr << "Error random number !" << std::endl;
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C class" << std::endl;
	else if (dynamic_cast<Base*>(p))
		std::cout << "Base class" << std::endl;
	else
		std::cerr << "Error" << std::endl;
}

void	identify(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C class" << std::endl;
	else if (dynamic_cast<Base*>(&p))
		std::cout << "Base class" << std::endl;
	else
		std::cerr << "Error" << std::endl;
}