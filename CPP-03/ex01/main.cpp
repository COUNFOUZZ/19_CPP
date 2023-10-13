#include "./ScavTrap.hpp"

int main(void) {
    ScavTrap bob("Bob");
    ScavTrap bob2;
    ScavTrap bob3(bob2);

    bob.guardGate();
    bob.attack("a pineaple");
    bob.takeDamage(100);
    bob.beRepaired(20);
    return 0;
}