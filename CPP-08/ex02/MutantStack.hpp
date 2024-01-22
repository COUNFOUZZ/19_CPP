#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<class T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::deque<T>::iterator iterator;
		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
};

#endif