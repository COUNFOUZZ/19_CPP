#include "./Fixed.hpp"

int const	Fixed::_fractionaryBits = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &a) {
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed(int const value) : _value(value * (1 << _fractionaryBits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value((roundf(value * (1 << _fractionaryBits)))) {
	std::cout << "Float constructor called" << std::endl;

}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & dest) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &dest)
		this->_value = dest._value;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	float	res;

	res = (float)this->_value / (1 << this->_fractionaryBits);
	return (res);
}

int	Fixed::toInt(void) const {
	return (this->_value >> this->_fractionaryBits);
}

std::ostream&	operator<<(std::ostream& output, Fixed const& fixed) {
	output << fixed.toFloat();
	return (output);
}