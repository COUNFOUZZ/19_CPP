#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>
#include <sstream>
#include <iterator>

template<typename T>
void	printContainer(const T& container) {
	typename T::const_iterator	it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

class PmergeMe {
	private:
		class InvalidStringStreamException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: string stream failed.";
				}
		};

		std::list<int>		_cList;
		std::vector<int>	_cVec;
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& dest);

		void	swap(std::list<int>::iterator& a, std::list<int>::iterator& b);

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

		void					parseInput(std::string str);
		void					insertionSort(void);
		void					mergeSort(void);
		const std::list<int>	getList(void) const;
		const std::vector<int>	getVector(void) const;
};

#endif