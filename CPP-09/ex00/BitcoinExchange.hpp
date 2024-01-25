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
		std::string						_pathFile;

		BitcoinExchange(void) {}
		BitcoinExchange(const BitcoinExchange& src) { static_cast<void>(src); }

		void	fillMapCSV(std::ifstream& file);
		bool	checkDate(const int year, const int month, const int day) const;
		bool	checkAndInitInput(std::string& date, double& coins, std::string& year, std::string& month, std::string& day) const;
		void	inputHandler(std::ifstream& file);
		void	printContainer(const std::map<std::string, double>& c) const;
		std::map<std::string, double>::const_iterator	getIterator(std::string& date) const;
		void	execute(const std::string& date, const double& coins, const std::map<std::string, double>::const_iterator& it) const;

		class ImpossibleToConvertStringStreamException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: impossible to convert the stringstream";
				}
		};
		class NegativeCoinException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: not a positive number.";
				}
		};
		class TooLargeNumberException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: too large a number.";
				}
		};
		class InvalidDateException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: bad input => ";
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