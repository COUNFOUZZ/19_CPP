#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0) {

}

PhoneBook::~PhoneBook(void) {

}

void	PhoneBook::addContact(void) {
	system("clear");
	std::cout << "**************************" << std::endl;
	std::cout << "*  CREATE A NEW CONTACT  *" << std::endl;
	std::cout << "**************************" << std::endl;
	if (_index == 8)
		_index = 0;
	_contact[_index].newContact(_index);
	++_index;
	system("clear");
}

void	PhoneBook::searchContact(void) const {
	system("clear");
	std::cout << "***************************" << std::endl;
	std::cout << "*     LIST OF CONTACT     *" << std::endl;
	std::cout << "***************************" << std::endl << std::endl;
	std::string	input;
	int			index(-1);

	for (int i = 0; i < 8; ++i)
		_contact[i].showMinimalist();
	while (input.empty()) {
		std::cout << "Index :" << std::endl;
		std::cout << "\t> ";
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
		for (int i = 0; i < (int)input.size(); ++i)
			if (!isdigit(input[i]))
				input.clear();
		if (input.empty())
			continue;
		index = std::atoi(input.c_str());
		if (!_contact[index].exist()) {
			_contact[index].showFull();
		} else {
			input.clear();
			std::cout << "There is no entry in this index !" << std::endl;
		}
	}
}