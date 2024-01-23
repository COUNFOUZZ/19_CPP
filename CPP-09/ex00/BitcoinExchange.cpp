#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const std::string& pathFile) : _bitcoinsPrices(), _pathFile(pathFile) {
	std::ifstream	file;

	file.open(this->_pathFile.c_str());
	if (file.fail())
		throw CouldNotOpenFileException();
	fillMapCSV(file);
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
			this->_bitcoinsPrices.insert(std::pair<std::string, double>(date, price));
		}
	}
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& dest) {
	if (this == &dest)
		return *this;
	this->_bitcoinsPrices = dest._bitcoinsPrices;
	this->_pathFile = dest._pathFile;
	return *this;
}