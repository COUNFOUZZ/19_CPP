#ifndef EASYFIND_HPP
#define	EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

class EmptyContainerException : public std::exception {
	public:
		const char*	what() const throw() {
			return "Exception error: Container is empty !";
		}
};

class NotFoundException : public std::exception {
	public:
		const char*	what() const throw() {
			return "Exception error: Element not found !";
		}
};

template<typename T>
typename T::iterator	easyfind(T& container, int toFind) {
	if (container.empty())
		throw EmptyContainerException();

	typename T::iterator	it;

	it = find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif