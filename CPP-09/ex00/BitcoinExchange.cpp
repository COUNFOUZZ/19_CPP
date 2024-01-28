#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const std::string& pathFile) : _csvContainer(), _pathFile(pathFile) {
	std::ifstream	csvFile, inputFile;

	csvFile.open("data.csv");
	inputFile.open(this->_pathFile.c_str());
	if (csvFile.fail() || inputFile.fail())
		throw CouldNotOpenFileException();
	fillMapCSV(csvFile);
	inputHandler(inputFile);
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

bool	BitcoinExchange::checkDate(const int year, const int month, const int day) const {
	if (month < 1 || month > 12 || day < 1)
		return false;
	switch (month){
		case 2:
			if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day == 29)
				return true;
			return (day <= 28);
		case 4:
		case 6:
		case 9:
		case 11:
			return (day <= 30);
		default:
			return (day <= 31);
	}
}

std::map<std::string, double>::const_iterator	BitcoinExchange::getIterator(const std::string date) const {
	std::map<std::string, double>::const_iterator	it;

	if (this->_csvContainer.count(date))
		return this->_csvContainer.find(date);
	it = this->_csvContainer.lower_bound(date);
	if (it != this->_csvContainer.begin())
		--it;
	return it;
}

void	BitcoinExchange::execute(const std::string& date, const double& coins, const std::map<std::string, double>::const_iterator& it) const {
	std::cout << date << " => " << coins << " = " << coins * it->second << std::endl;
}

void	BitcoinExchange::inputHandler(std::ifstream& file) {
	std::string	line, date;
	int			year, month, day;
	char		sep1, sep2, sep3;
	double		amount;

	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			try {
				std::stringstream	ssLine(line);

				ssLine >> year >> sep1 >> month >> sep2 >> day >> sep3 >> amount;
				if (ssLine.fail() || !checkDate(year, month, day) || sep1 != '-' || sep2 != '-' || sep3 != '|' || line[line.find('|') - 1] != ' ' || line[line.find('|') + 1] != ' ')
					throw BadInputException();
				else if (amount < 0)
					throw NegativeCoinException();
				else if (amount > 1000)
					throw TooLargeNumberException();
				date = line.substr(0, line.find(" |"));
				execute(date, amount, getIterator(date));
			} catch (BadInputException& e) {
				std::cerr << e.what() << line << std::endl;
			} catch	(std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	file.close();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& dest) {
	if (this == &dest)
		return *this;
	this->_csvContainer = dest._csvContainer;
	this->_pathFile = dest._pathFile;
	return *this;
}