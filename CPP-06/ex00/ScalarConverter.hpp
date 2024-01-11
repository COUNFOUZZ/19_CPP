#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cfloat>
#include <string>
#include <stdexcept>
#include <iomanip>

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

		static size_t	findPrecision(std::string input);
		static int		processInput(const std::string& input, std::stringstream& ss);
		static int		valueType(const std::string input, int dot, int f);
		static void		print(std::string input, size_t precision);
		static void		print(char input, size_t precision);
		static void		print(int input, size_t precision);
		static void		print(float input, size_t precision);
		static void		print(double input, size_t precision);
		static void		parseInputAndFillInfos(const std::string& input, int& sign, int& printable, int& dot, int& f);
		static void		execute(std::string& input, std::stringstream& ss, int type);

	public:
		~ScalarConverter(void);

		ScalarConverter&	operator=(const ScalarConverter& dest);

		static void	convert(std::string toBeConverted);
};

#endif