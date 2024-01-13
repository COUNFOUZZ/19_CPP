#include "Data.hpp"

Data::Data(void) : _value(0) {}
Data::Data(unsigned int setValue) : _value(setValue) {}
Data::Data(const Data& src) : _value(0) { *this = src; }
Data::~Data(void) {}

Data&	Data::operator=(const Data& dest) {
	if (this == &dest)
		return *this;
	this->_value = dest._value;
	return *this;
}

unsigned int	Data::getValue(void) const {
	return this->_value;
}