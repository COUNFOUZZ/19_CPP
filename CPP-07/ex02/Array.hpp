#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;
		class OutOfBoundException : public std::exception {
			public:
				const char*	what() const throw() {
					return "this index is out of bounds !";
				}
		};

	public:
		Array<T>(void) : _array(NULL), _size(0) {}
		Array<T>(unsigned int n) : _array(new T[n]), _size(n) {}
		~Array<T>(void) { 
			delete[] this->_array;
			this->_array = NULL;
		}

		Array<T>(const Array<T>& toCopy) : _array(NULL), _size(0) {
			*this = toCopy;
		}

		Array<T>&	operator=(const Array<T>& dest) {
			if (this == &dest)
				return *this;
			this->_size = dest._size;
			if (this->_size > 0) {
				if (this->_array) {
					delete[] this->_array;
					this->_array = NULL;
				}
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; ++i)
					this->_array[i] = dest._array[i];
			}
			return *this;
		}

		T& operator[](int index) {
			if (index < 0 || index >= static_cast<int>(_size))
				throw OutOfBoundException();
			return _array[index];
		}

		unsigned int	size(void) const { return this->_size; }
};

#endif