#include "ClassAndFunctions.hpp"

// int main(void) {
// 	Base*	base;
// 	base = generate();
// 	identify(base);
// 	identify(*base);
// 	delete base;

// 	std::cout << std::endl;

// 	Base*	a = new A();
// 	identify(a);
// 	identify(*a);
// 	delete a;

// 	Base*	b = new B();
// 	identify(b);
// 	identify(*b);
// 	delete b;

// 	Base*	c = new C();
// 	identify(c);
// 	identify(*c);
// 	delete c;
// 	return 0;
// }

int main(){
    Base* b;
    b = generate();
    Base& ref = *b;
    identify(b);
    identify(ref);
    delete b;
    return 0;
}