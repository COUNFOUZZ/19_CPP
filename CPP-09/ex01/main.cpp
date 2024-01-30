#include "RPN.hpp"

int	main(int argc, const char** argv) {
	try {
		if (argc != 2)
			throw RPN::InvalidArg();
		RPN	obj(argv[1]);
	} catch (RPN::BadInputException& e) {
		std::cout << e.what() << argv[1] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}