#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_value;
		static int const	_fractionaryBits;

	public:
		Fixed(void);
		Fixed(Fixed &a);
		~Fixed(void);
		Fixed&	operator=(Fixed const & dest);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif