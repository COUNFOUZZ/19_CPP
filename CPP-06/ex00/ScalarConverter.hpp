#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <float.h>
#include <string>
#include <stdexcept>

class ScalarConverter {
	private:
		enum	types {
			e_fail = -1,
			e_char,
			e_int,
			e_float,
			e_double
		};
		class InvalidConvertException : public std::exception {
			public:
				const char* what() const throw();
		};
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);

		static void	print(std::string input);
		static void	print(char input);
		static void	print(int input);
		static void	print(float input);
		static void	print(double input);
		static void	parseInputAndFillInfos(const std::string& input, int& sign, int& printable, int& dot, int& f, int& i_precision);
		static int	processInput(const std::string& input, std::stringstream& ss);
		static int	valueType(const std::string input, int dot, int f);
		static void	execute(std::stringstream& ss, int type);

	public:
		~ScalarConverter(void);

		ScalarConverter&	operator=(const ScalarConverter& dest);

		static void	convert(std::string toBeConverted);
};

#endif