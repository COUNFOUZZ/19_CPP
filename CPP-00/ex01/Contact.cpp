#include "./Contact.hpp"

Contact::Contact(void) : _index(-1) {
}

Contact::~Contact(void) {

}

void	Contact::_askInfos(std::string& info, std::string const title) {
	info.clear();
	while (info.empty()) {
		std::cout << title << " :" << std::endl;
		std::cout << "\t> ";
		if (!std::getline(std::cin, info))
			exit(EXIT_FAILURE);
		if (!title.compare("Phone number")) {
			for (int i = 0; i < (int)info.size(); ++i)
				if (!isdigit(info[i]))
					info.clear();
		}
	}
}

void	Contact::newContact(int index) {
	std::cout << std::endl;
	this->_index = index;
	_askInfos(this->_firstname, "Firstname");
	_askInfos(this->_lastname, "Lastname");
	_askInfos(this->_nickname, "Nickname");
	_askInfos(this->_phoneNumber, "Phone number");
	_askInfos(this->_darkSecret, "Darkest secret");
}

std::string	Contact::_limit10char(std::string info) const {
	std::string	str(10, ' ');

	if (info.size() > 10) {
		str = info.substr(0, 9);
		str.append(".");
	}
	else
		str.replace(str.size() - info.size(), info.size(), info);
	return (str);
}

void	Contact::showMinimalist(void) const {
	if (!_firstname.empty()) {
		std::cout << "         " << _index << '|';
		std::cout << _limit10char(_firstname) << '|';
		std::cout << _limit10char(_lastname) << '|';
		std::cout << _limit10char(_nickname) << '|' << std::endl;
	} else {
		std::cout << "          |";
		std::cout << "          |";
		std::cout << "          |";
		std::cout << "          |" << std::endl;
	}
}

int	Contact::exist(void) const {
	if (this->_index == -1)
		return (1);
	return (0);
}

void	Contact::showFull(void) const {
	system("clear");
	std::string	input;

	std::cout << "Firstname : " << this->_firstname << std::endl;
	std::cout << "Lastname : " << this->_lastname << std::endl;
	std::cout << "Nickname : " << this->_nickname << std::endl;
	std::cout << "Phone number : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->_darkSecret << std::endl;
	std::cout << std::endl << "Press [ENTER] to continue..." << std::endl;
	if (!std::getline(std::cin, input))
		exit(EXIT_SUCCESS);
	system("clear");
}