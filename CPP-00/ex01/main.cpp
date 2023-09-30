#include "./PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook;
	std::string	input;

	while (1) {
		std::cout << "*****************" << std::endl;
		std::cout << "*   Main menu   *" << std::endl;
		std::cout << "*****************" << std::endl;
		std::cout << std::endl;
		std::cout << "ADD, SEARCH, EXIT" << std::endl << std::endl;
		std::cout << "\t> ";
		if (!std::getline(std::cin, input))
			break;	
		if (!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.searchContact();
		else if (!input.compare("EXIT"))
			break;
		else {
			system("clear");
			std::cout << '[' << input << ']' << " is a bad input !" << std::endl;
		}
	}
	return (0);
}