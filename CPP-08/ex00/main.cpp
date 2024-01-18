#include "easyfind.hpp"

int	main(void) {
	try {
		std::vector<int>			vect;

		vect.push_back(19);
		vect.push_back(1);
		vect.push_back(9);
		vect.push_back(3);
		vect.push_back(56);
		vect.push_back(32);
		vect.push_back(89);

		std::vector<int>::iterator	it;

		it = easyfind(vect, 3);
		std::cout << *it << std::endl;
		it = easyfind(vect, 56);
		std::cout << *it << std::endl;
		it = easyfind(vect, 99);
		std::cout << *it << std::endl;
	
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}