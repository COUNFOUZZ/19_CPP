#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { static_cast<void>(src); }
ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& dest) {
	static_cast<void>(dest);
	return *this;
}

const char*	ScalarConverter::InvalidConvertException::what() const throw() {
	return "is an invalid input to convert !";
}

void	ScalarConverter::print(char input) {
	std::cout << "char: " << "'" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

void	ScalarConverter::print(int input) {
	std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << input << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

void	ScalarConverter::print(float input) {
	std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void	ScalarConverter::print(double input) {
	std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::parseInput(const std::string& input, int& sign, int& printable, int& dot, int& f, int& i_precision) {
	int	digit = 0, ch = 0;

	for (int i = 0; input[i]; ++i) {
		if (input[i] == '.') {
			++dot;
			i_precision = i;
		}
		else if (input[i] == '-')
			++sign;
		else if (input[i] == 'f')
			++f;
		else if (isprint(input[i]) && !isalnum(input[i]))
			++printable;
		else if (isdigit(input[i]))
			++digit;
		else if (isalpha(input[i]) && input[i] != 'f')
			++ch;
	}
	std::cout
	<<	"[input.length()] = " << input.length() << std::endl
	<< "[dot] = " << dot << std::endl
	<< "[sign] = " << sign << std::endl
	<< "[f] = " << f << std::endl
	<< "[printable] = " << printable << std::endl
	<< "[i_precision] = " << i_precision << std::endl << std::endl;
	if ((digit && ch) || dot > 1 || sign > 1 || f > 1 || printable > 1 
		|| (f == 1 && input[input.length() - 1] != 'f') 
		|| (sign == 1 && input[0] != '-'))
		throw InvalidConvertException();
}

void	ScalarConverter::processInput(const std::string& input) {
	int sign = 0, printable = 0, dot = 0, f = 0, i_precision = 0, totalAfterDot = 0;

	parseInput(input, sign, printable, dot, f, i_precision);
	if (i_precision)
		totalAfterDot = input.length() - (i_precision + 1);
	std::cout << totalAfterDot << std::endl;
	if (!dot && !f) {
		int	value_int = std::stoi(input);
		print(value_int);
	} else if (dot && f) {
		float value_float = std::stof(input);
		print(value_float);
	} else if (dot && !f) {
		double value_double = std::stod(input);
		print(value_double);
	}
}

void	ScalarConverter::convert(std::string toBeConverted) {
	try {
		if (toBeConverted.length() == 1)
			print(toBeConverted[0]);
		else
			processInput(toBeConverted);
	}
	catch (std::exception& e) {
		std::cerr << "[" << toBeConverted << "] " << e.what() << std::endl;
	}
}