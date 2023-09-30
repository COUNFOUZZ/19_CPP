#include "Zombie.hpp"

int	main(void) {
	Zombie* horde = zombieHorde(10, "Heap");
	delete [] horde;
	return (0);
}
