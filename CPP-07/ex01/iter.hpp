#ifndef ITER_HPP
#define	ITER_HPP

#include <iostream>

template<typename Titer>
void	iter(Titer* array, const size_t length, void (*f)(Titer&)) {
		f(array[i]);
}

template<typename Titer>
void	iter(const Titer* array, const size_t length, void (*f)(const Titer&)) {
		f(array[i]);
}

#endif