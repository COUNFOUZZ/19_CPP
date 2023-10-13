#include "./FragTrap.hpp"

int main(void) {
    FragTrap bob("Bob");
    FragTrap bob2;
    FragTrap bob3(bob2);

    bob.highFivesGuys();
    bob.attack("a pineaple");
    bob.takeDamage(100);
    bob.beRepaired(20);
    return 0;
}