#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
		unsigned int	_value;

	public:
		Data(void);
		Data(unsigned int setValue);
		Data(const Data& src);
		~Data(void);

		Data& operator=(const Data& dest);

		unsigned int	getValue(void) const;
};

#endif