#ifndef RPN_CPP
#define RPN_CPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
	private:
		class ErrorStringStreamException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: stringstream failed.";
				}
		};
		std::stack<int>	_cStack;
		RPN(void);
		RPN(const RPN& src);
		RPN&	operator=(const RPN& dest);

		bool	isSign(const char current) const;
		void	execute(const char sign);

	public:
		class InvalidArg : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: invalid number of argument.";
				}
		};
		class BadInputException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: bad input => ";
				}
		};
		RPN(const std::string str);
		~RPN(void);
};

#endif