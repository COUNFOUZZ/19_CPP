#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <sstream>
#include <iterator>

class PmergeMe {
	private:
		class InvalidStringStreamException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: string stream failed.";
				}
		};
		std::list<int>	_cList;
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& dest);

	public:
		class InvalidArgException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Error: invalid number of argument.";
				}
		};
		class BadInputException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: invalid input => ";
				}
		};
		PmergeMe(void);
		~PmergeMe(void);

		void	parseInput(std::string str);
		void	printContainer(void) const;
};

#endif