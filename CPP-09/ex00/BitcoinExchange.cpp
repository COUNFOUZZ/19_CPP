#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const std::string& pathFile) : _csvContainer(), _inputContainer(), _pathFile(pathFile) {
	std::ifstream	csvFile, inputFile;

	csvFile.open("data.csv");
	inputFile.open(this->_pathFile.c_str());
	if (csvFile.fail() || inputFile.fail())
		throw CouldNotOpenFileException();
	fillMapCSV(csvFile);
	fillMapInput(inputFile);
	printContainer(this->_inputContainer);
}

void	BitcoinExchange::fillMapCSV(std::ifstream& file) {
	std::string			line, date, strPrice;
	std::stringstream	ssPrice;
	double				price;

	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			date = line.substr(0, line.find(','));
			strPrice = line.substr(line.find(',') + 1);
			ssPrice << strPrice;
			ssPrice >> price;
			if (ssPrice.fail())
				throw ImpossibleToConvertStringStreamException();
			ssPrice.clear();
			ssPrice.str("");
			this->_csvContainer.insert(std::pair<std::string, double>(date, price));
		}
	}
	file.close();
}

void	BitcoinExchange::fillMapInput(std::ifstream& file) {
	std::string			line, date, strPrice;
	std::stringstream	ssPrice;
	double				price;

	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			//	need to be changed !
			// date = line.substr(0, line.find('|'));
			// strPrice = line.substr(line.find('|') + 1);		 
			// std::cout << date << " " << strPrice << std::endl; 
			ssPrice << strPrice;
			ssPrice >> price;
			if (ssPrice.fail())
				throw ImpossibleToConvertStringStreamException();
			ssPrice.clear();
			ssPrice.str("");
			this->_inputContainer.insert(std::pair<std::string, double>(date, price));
		}
	}
	file.close();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& dest) {
	if (this == &dest)
		return *this;
	this->_csvContainer = dest._csvContainer;
	this->_inputContainer = dest._inputContainer;
	this->_pathFile = dest._pathFile;
	return *this;
}

void	BitcoinExchange::printContainer(const std::map<std::string, double>& c) const {
	std::map<std::string, double>::const_iterator	it;

	for (it = c.begin(); it != c.end(); ++it)
		std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
}