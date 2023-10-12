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

Fixed&	Fixed::operator=(Fixed const & dest) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &dest)
	this->_value = dest._value;
	return (*this);
}

bool	Fixed::operator>(Fixed const & dest) const {
	return (this->_value > dest._value);
}

bool	Fixed::operator<(Fixed const & dest) const {
	return (this->_value < dest._value);
}

bool	Fixed::operator>=(Fixed const & dest) const {
	return (this->_value >= dest._value);
}

bool	Fixed::operator<=(Fixed const & dest) const {
	return (this->_value <= dest._value);
}

bool	Fixed::operator==(Fixed const & dest) const {
	return (this->_value == dest._value);
}

bool	Fixed::operator!=(Fixed const & dest) const {
	return (this->_value != dest._value);
}

Fixed&	Fixed::operator++(int) {
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(int) {
	this->_value--;
	return (*this);
}

Fixed&	Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator+(Fixed const & dest) {
	Fixed	res;

	res.setRawBits(this->_value + dest._value);
	return (res);
}

Fixed Fixed::operator-(Fixed const & dest) {
	Fixed	res;

	res.setRawBits(this->_value - dest._value);
	return (res);
}

Fixed Fixed::operator*(Fixed const & dest) {
	Fixed	res;

	res.setRawBits((this->_value * dest._value) >> this->_fractionaryBits);
	return (res);
}

Fixed Fixed::operator/(Fixed const & dest) {
	Fixed	res;

	if (dest == 0) {
		std::cout << "Can't be divide by 0 !" << std::endl;
		return (0);
	}
	res.setRawBits((this->_value << this->_fractionaryBits) / dest._value);
	return (res);
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

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b) {
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b) {
	return (a > b ? a : b);
}

std::ostream&	operator<<(std::ostream& output, Fixed const& fixed) {
	output << fixed.toFloat();
	return (output);
}