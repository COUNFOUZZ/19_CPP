#include "Span.hpp"

Span::Span(void) : _container(0), _sizeMax(0) {}
Span::Span(const Span& src) { *this = src; }
Span::Span(unsigned int N) : _sizeMax(N) {}
Span::~Span(void) {}

Span&	Span::operator=(const Span& dest) {
	if (this == &dest)
		return *this;
	this->_container.assign(dest._container.begin(), dest._container.end());
	this->_sizeMax = dest._sizeMax;
	return *this;
}

void	Span::addNumber(int nbr) {
	if (this->_container.size() >= this->_sizeMax)
		throw ContainerFullException();
	if (nbr > INT_MAX || nbr < INT_MIN)
		throw MaxMinINTException();
	this->_container.push_back(nbr);
}

unsigned int	Span::shortestSpan(void) const {
	if (this->_sizeMax < 2)
		throw NoSpanFoundException();

	std::vector<int>	cp_vector(this->_container);
	std::sort(cp_vector.begin(), cp_vector.end());
	int	min = INT_MAX;
	for (size_t i = 1; i < cp_vector.size(); ++i) {
		int	currentDiff = cp_vector[i] - cp_vector[i - 1];
		min = std::min(min, currentDiff);
	}
	return min;
}

unsigned int	Span::longestSpan(void) const {
	if (this->_sizeMax < 2)
		throw NoSpanFoundException();

	std::vector<int>::const_iterator	max, min;

	max = std::max_element(this->_container.begin(), this->_container.end());
	min = std::min_element(this->_container.begin(), this->_container.end());
	return *max - *min;
}

void	Span::rangeOfIterator(unsigned int size, int value) {
	for (size_t	i = 0; i <  size; ++i)
		this->addNumber(value);
}