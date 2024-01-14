#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename Tswap>
void	swap(Tswap& a, Tswap& b) {
	Tswap	tmp = a;

	a = b;
	b = tmp;
}

template<typename Tmin>
const Tmin&	min(const Tmin& a, const Tmin& b) {
	return (a >= b ? b : a);
}

template<typename Tmax>
const Tmax&	max(const Tmax& a, const Tmax& b) {
	return (a >= b ? a : b);
}

#endif