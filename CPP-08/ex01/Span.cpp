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

void	Span::addNumber(unsigned int nbr) {
	if (this->_container.size() >= this->_sizeMax)
		throw ContainerFullException();
	if (nbr > UINT_MAX)
		throw MaxUINTException();
	this->_container.push_back(nbr);
}

unsigned int	Span::shortestSpan(void) const {
	if (this->_sizeMax < 2)
		throw NoSpanFoundException();

	std::vector<unsigned int>	cp_vector(this->_container);
	std::sort(cp_vector.begin(), cp_vector.end());
	unsigned int	min = UINT_MAX;
	for (size_t i = 1; i < cp_vector.size(); ++i) {
		unsigned int	currentDiff = cp_vector[i] - cp_vector[i - 1];
		min = std::min(min, currentDiff);
	}
	return min;
}

unsigned int	Span::longestSpan(void) const {
	if (this->_sizeMax < 2)
		throw NoSpanFoundException();

	std::vector<unsigned int>::const_iterator	max, min;

	max = std::max_element(this->_container.begin(), this->_container.end());
	min = std::min_element(this->_container.begin(), this->_container.end());
	return *max - *min;
}