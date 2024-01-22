#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T, typename Y = std::deque<T> >

class	MutantStack : public std::stack<T, Y> {
	private:
		std::stack<T, Y>	_stack;
		MutantStack&		operator=(const MutantStack& dest) { static_cast<void>(dest); return *this; }

	public:
		MutantStack(void) : std::stack<T, Y>() {};
		MutantStack(const MutantStack &copy) : std::stack<T, Y>(copy) {};
		~MutantStack(void) {};

		typedef typename Y::iterator iterator;
		typedef typename Y::const_iterator const_iterator;

		iterator		begin(void) 		{ return this->c.begin(); }
		iterator		end(void) 			{ return this->c.end(); }
		const_iterator	begin(void) const 	{ return this->c.begin(); }
		const_iterator	end(void) 	const 	{ return this->c.end(); }
};

#endif