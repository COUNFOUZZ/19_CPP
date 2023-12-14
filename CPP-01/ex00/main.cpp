#include "Zombie.hpp"

int	main(void) {
	Zombie stack_zombie("Stack");
	Zombie *heap_zombie = newZombie("Heap");

	stack_zombie.announce();
	heap_zombie->announce();
	randomChump("RandomChump_Stack_In_Function");
	delete heap_zombie;
	return (0);
}
