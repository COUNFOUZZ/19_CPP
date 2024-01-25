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

bool	BitcoinExchange::checkDate(int year, int month, int day) const {
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

void	BitcoinExchange::checkInput(std::string& date, double& coins) const {
	std::string			year, month, day;
	std::stringstream	ssYear, ssMonth, ssDay;
	int					iYear, iMonth, iDay;

	year = date.substr(0, 4);
	month = date.substr(year.length() + 1, 2);
	day = date.substr(year.length() + month.length() + 2);

	ssYear << year;
	ssMonth << month;
	ssDay << day;

	ssYear >> iYear;
	if (ssYear.fail())
		throw ImpossibleToConvertStringStreamException();
	ssMonth >> iMonth;
	if (ssMonth.fail())
		throw ImpossibleToConvertStringStreamException();
	ssDay >> iDay;
	if (ssDay.fail())
		throw ImpossibleToConvertStringStreamException();

	try {
		if (coins < 0)
			throw NegativeCoinException();
		else if (coins > 1000)
			throw TooLargeNumberException();
		else if (!checkDate(iYear, iMonth, iDay))
			throw InvalidDateException();
		
	} catch (InvalidDateException& e) {
		std::cerr << e.what() << year << "-" << month << "-" << day << std::endl;
	} catch	(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	ssYear.clear();
	ssYear.str("");
	ssMonth.clear();
	ssMonth.str("");
	ssDay.clear();
	ssDay.str("");
}

void	BitcoinExchange::inputHandler(std::ifstream& file) {
	std::string			line, date, strCoins;
	std::stringstream	ssCoins;
	double				coins;

	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			date = line.substr(0, line.find('|') - 1);
			strCoins = line.substr(line.find('|') + 2); 
			ssCoins << strCoins;
			ssCoins >> coins;
			if (ssCoins.fail())
				throw ImpossibleToConvertStringStreamException();
			checkInput(date, coins);
			ssCoins.clear();
			ssCoins.str("");
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

void	BitcoinExchange::printContainer(const std::map<std::string, double>& c) const {
	std::map<std::string, double>::const_iterator	it;

	for (it = c.begin(); it != c.end(); ++it)
		std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
}