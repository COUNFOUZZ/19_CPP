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

size_t	ScalarConverter::findPrecision(std::string input) {
	size_t	precision = -1;

	precision = (input.length() - input.find('.') - 1);
	return precision;
}

void	ScalarConverter::print(std::string input, size_t precision) {
	static_cast<void>(precision);

	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::print(char input, size_t precision) {
	static_cast<void>(precision);

	if (!isascii(static_cast<char>(input)))
		std::cout << "char: " << "Impossible" << std::endl;
	else if (isascii(static_cast<char>(input)) && !isprint(static_cast<char>(input)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

void	ScalarConverter::print(int input, size_t precision) {
	static_cast<void>(precision);

	if (!isascii(static_cast<char>(input)))
		std::cout << "char: " << "Impossible" << std::endl;
	else if (isascii(static_cast<char>(input)) && !isprint(static_cast<char>(input)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << input << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

void	ScalarConverter::print(float input, size_t precision) {
	if (!isascii(static_cast<char>(input)))
		std::cout << "char: " << "Impossible" << std::endl;
	else if (isascii(static_cast<char>(input)) && !isprint(static_cast<char>(input)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	if (input < INT_MIN || input > INT_MAX)
		std::cout << "int: " << "overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(precision) << input << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(input) << std::endl;
}

void	ScalarConverter::print(double input, size_t precision) {
	if (!isascii(static_cast<char>(input)))
		std::cout << "char: " << "Impossible" << std::endl;
	else if (isascii(static_cast<char>(input)) && !isprint(static_cast<char>(input)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(input) << "'" << std::endl;
	if (input < INT_MIN || input > INT_MAX)
		std::cout << "int: " << "overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	if (input < FLT_MIN || input > FLT_MAX)
		std::cout << "float: " << "overflow" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(input) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(precision) << input << std::endl;
}

void	ScalarConverter::parseInputAndFillInfos(const std::string& input, int& sign, int& printable, int& dot, int& f) {
	int	digit = 0, ch = 0;
	size_t	i_precision = -1;

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
	if ((digit && ch) || dot > 1 || sign > 1 || f > 1 || printable > 1 
		|| (f == 1 && input[input.length() - 1] != 'f') 
		|| (sign == 1 && input[0] != '-')
		|| (input[input.length() - 1] == 'f' && i_precision == input.length() - 2))
		throw InvalidConvertException();
}

int	ScalarConverter::valueType(const std::string input, int dot, int f) {

	if (!dot && f)																// fail
		return e_fail;
	else if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))	// char
		return e_char;
	else if ((!dot && !f) || (input.length() == 1 && isdigit(input[0])))		// int
		return e_int;
	else if (dot && f)															// float
		return e_float;
	else if (dot && !f)															// double
		return e_double;
	return e_fail;
}

int	ScalarConverter::processInput(const std::string& input, std::stringstream& ss) {
	int sign = 0, printable = 0, dot = 0, f = 0, type = 0;

	parseInputAndFillInfos(input, sign, printable, dot, f);
	type = valueType(input, dot, f);
	if (type == e_float) {
		std::string	inputFloat(input.substr(0, input.length() - 1));
		ss.str(inputFloat);
	}
	else
		ss.str(input);
	return type;
}

void	ScalarConverter::execute(std::string& input, std::stringstream& ss, int type) {
	size_t	precision = -1;

	switch (type) {
		case e_char:
			char	valueChar;
			ss >> valueChar;
			if (ss.fail())
				throw std::runtime_error("Impossible to convert string to char !");
			print(valueChar, 0);
		break;
		case e_int:
			int	valueInt;
			ss >> valueInt;
			if (ss.fail())
				throw std::runtime_error("Impossible to convert string to int !");
			print(valueInt, 0);
		break;
		case e_float:
			float	valueFloat;
			ss >> valueFloat;
			if (ss.fail())
				throw std::runtime_error("Impossible to convert string to float !");
			precision = findPrecision(input);
			print(valueFloat, precision - 1);
		break;
		case e_double:
			double	valueDouble;
			ss >> valueDouble;
			if (ss.fail())
				throw std::runtime_error("Impossible to convert string to double !");
			precision = findPrecision(input);
			print(valueDouble, precision);
		break;
		default:
			throw InvalidConvertException();
	}
}

void	ScalarConverter::convert(std::string toBeConverted) {
	try {
		std::stringstream	ss;
		int					type = -1;

		if (toBeConverted == "nan" || toBeConverted == "-inf" || toBeConverted == "+inf") {
			print(toBeConverted, 0);
			return;
		}
		type = processInput(toBeConverted, ss);
		execute(toBeConverted, ss, type);
	} catch (std::exception& e) {
		std::cerr << "[" << toBeConverted << "] " << e.what() << std::endl;
	}
}