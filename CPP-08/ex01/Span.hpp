#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class Span {
	private:
		std::vector<unsigned int>	_container;
		unsigned int				_sizeMax;
		class ContainerFullException : public std::exception {
			public:
				const char*	what(void)	const throw() {
					return "Exception error: the container is full !";
				}
		};
		class MaxUINTException : public std::exception {
			public:
				const char*	what(void)	const throw() {
					return "Exception error: your number is greater than an unsigned int !";
				}
		};
		class NoSpanFoundException : public std::exception {
			public:
				const char*	what(void)	const throw() {
					return "Exception error: no span can be found !";
				}
		};
		Span(void);

	public:
		Span(const Span& src);
		Span(unsigned int N);
		~Span(void);

		Span&	operator=(const Span& dest);

		void			addNumber(unsigned int nbr);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
};

#endif