#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <vector>
#include <sstream>
#include <iterator>
#include <sys/time.h>

#define	SIZE_ARRAY	2

template<typename T>
void	printContainer(const T& container) {
	typename T::const_iterator	it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename T>
void insertionSort(T& container) {
	typename T::iterator it, second;

	for (it = container.begin(); it != container.end(); ++it) {
		int key = *it;
		second = it;
		while (second != container.begin() && key < *(--second)) {
			std::swap(*it, *second);
			--it;
		}
	}
}

template<typename T>
void	merge(T& container, T& left, T& right) {
	typename T::iterator	itLeft = left.begin();
	typename T::iterator	itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
		*itLeft > *itRight ? container.push_back(*itRight++) : container.push_back(*itLeft++);
	while (itLeft != left.end())
		container.push_back(*itLeft++);
	while (itRight != right.end())
		container.push_back(*itRight++);
}

template<typename T>
void	mergeSortHanling(T& container) {
	if (container.size() <= SIZE_ARRAY) {
		insertionSort(container);
		return;
	}
	T						left, right;
	typename T::iterator	middle = container.begin();
	
	std::advance(middle, container.size() / 2);
	left.assign(container.begin(), middle);
	right.assign(middle, container.end());
	mergeSortHanling(left);
	mergeSortHanling(right);
	container.clear();
	merge(container, left, right);
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
		double				timeList, timeVector;

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
		class DoubleException : public std::exception {
			public:
				const char* what(void) const throw() {
					return "Error: each element are not unique.";
				}
		};

		PmergeMe(void);
		~PmergeMe(void);

		void				parseInput(std::string str);
		void				sort(void);
		std::list<int>&		getList(void);
		std::vector<int>&	getVector(void);
};

#endif