#include "./Harl.hpp"

int	main(int argc, const char **argv) {
	if (argc != 2)
		return (std::cerr << "Invalid args" << std::endl, 1);
	Harl	instance;

	instance.complain(argv[1]);
	return (0);
}