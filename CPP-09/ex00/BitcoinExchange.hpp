#ifndef BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_csvContainer;
		std::map<std::string, double>	_inputContainer;
		std::string						_pathFile;

		BitcoinExchange(void) {}
		BitcoinExchange(const BitcoinExchange& src) { static_cast<void>(src); }

		void	fillMapCSV(std::ifstream& file);
		void	fillMapInput(std::ifstream& file);
		void	printContainer(const std::map<std::string, double>& c) const;

		class ImpossibleToConvertStringStreamException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: impossible to convert the stringstream";
				}
		};

	public:
		class CouldNotOpenFileException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: could not open file.";
				}
		};
		BitcoinExchange(const std::string& pathFile);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& dest);

};

#endif