#include "PmergeMe.hpp"

int main(int argc, const char** argv) {
	int			i = 0;

	try {
		if (argc < 2)
			throw PmergeMe::InvalidArgException();
		PmergeMe	obj;

		for (i = 1; i < argc; ++i)
			obj.parseInput(argv[i]);
		obj.sort();
	} catch (PmergeMe::DoubleException& e) {
		std::cerr << e.what() << std::endl;
	} catch (PmergeMe::BadInputException& e) {
		std::cerr << e.what() << argv[i] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}