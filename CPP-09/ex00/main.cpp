#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw BitcoinExchange::CouldNotOpenFileException();
		BitcoinExchange	bitcoin(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}