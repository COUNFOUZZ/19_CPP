#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		class InvalidConvertException : public std::exception {
			public:
				const char* what() const throw();
		};
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);

		static void	print(char input);
		static void	print(int input);
		static void	print(float input);
		static void	print(double input);
		static void	processInput(const std::string& input);
		static void	parseInput(const std::string& input, int& sign, int& printable, int& dot, int& f, int& i_precision);

	public:
		~ScalarConverter(void);

		ScalarConverter&	operator=(const ScalarConverter& dest);

		static void	convert(std::string toBeConverted);
};

#endif