#include "./Harl.hpp"

Harl::Harl(void) {
	this->_ftPtr[0] = &Harl::_debug;
	this->_ftPtr[1] = &Harl::_info;
	this->_ftPtr[2] = &Harl::_warning;
	this->_ftPtr[3] = &Harl::_error;
}
Harl::~Harl(void) {}

void	Harl::_debug(void) const {
	std::cout << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::_info(void) const {
	std::cout << "[INFO] - I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::_warning(void) const {
	std::cout << "[WARNING] - I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) const {
	std::cout << "[ERROR] - This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const {
	std::string	options[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < (int)level.length(); ++i)
		level[i] = toupper(level[i]);
	for (int i = 0; i < 4; ++i) {
		if (level.compare(options[i]) == 0) {
			(this->*_ftPtr[i])();
			return;
		}
	}
	std::cout << "Bad level !" << std::endl;
}