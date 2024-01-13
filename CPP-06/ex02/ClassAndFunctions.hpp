#ifndef CLASSANDFUNCTIONS_HPP
#define CLASSANDFUNCTIONS_HPP

#include <iostream>
#include <ctime>
#include <stdexcept>

class Base { public: virtual ~Base(void) {} };
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif