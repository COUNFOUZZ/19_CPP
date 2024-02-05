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

template<typename T>
void	swap(typename T::iterator& a, typename T::iterator& b) {
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename T>
void insertionSort(T& container) {
	if (container.size() < 2)
		return;
	typename T::iterator it, second;

	for (it = container.begin(); it != container.end(); ++it) {
		int key = *it;
		second = it;
		while (second != container.begin() && key < *(--second)) {
			std::swap(it, second);
			--it;
		}
	}
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

		void	mergeSortHanling(std::list<int>& list);
		// void	sortList(void);
		// void	sortVector(void);

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
		// void					insertionSort(int listOrVector);
		void					mergeSort(void);
		std::list<int>&	getList(void);
		std::vector<int>&	getVector(void);
};

#endif