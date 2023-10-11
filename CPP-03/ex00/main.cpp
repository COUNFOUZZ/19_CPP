#include "./ClapTrap.hpp"

int main(void) {
    ClapTrap a;
    ClapTrap bob("Bob");
    ClapTrap dan("Dan");
    ClapTrap jo(bob);
    ClapTrap b;

    b = dan;

    dan.attack("jo");
    jo.takeDamage(100);
    jo.beRepaired(10);
	jo.attack("dan");

    dan.takeDamage(9);
    for (int i = 0; i < 9; ++i) {
        dan.beRepaired(1);
    }
    dan.attack("a trash can");
    return 0;
}