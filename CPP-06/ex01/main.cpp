#include "Serializer.hpp"

int main(void) {
	Data*		a = new Data(19);
	uintptr_t	b;

	std::cout << a->getValue() << std::endl;
	b = Serializer::serialize(a);
	std::cout << b << std::endl;
	a = Serializer::deserialize(b);
	std::cout << a->getValue() << std::endl;
	delete a;

	return 0;
}