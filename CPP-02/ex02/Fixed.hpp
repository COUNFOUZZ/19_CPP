#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_value;
		static int const	_fractionaryBits;

	public:
		Fixed(void);
		Fixed(Fixed const &a);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		Fixed&	operator=(Fixed const & dest);
		bool	operator>(Fixed const & dest) const;
		bool	operator<(Fixed const & dest) const;
		bool	operator>=(Fixed const & dest) const;
		bool	operator<=(Fixed const & dest) const;
		bool	operator==(Fixed const & dest) const;
		bool	operator!=(Fixed const & dest) const;
		Fixed&	operator++(int);
		Fixed&	operator++(void);
		Fixed&	operator--(int);
		Fixed&	operator--(void);
		Fixed	operator*(Fixed const & dest);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& output, Fixed const& fixed);

#endif