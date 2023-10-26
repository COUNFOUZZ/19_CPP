#include "./DiamondTrap.hpp"

int main(void) {
    DiamondTrap a;

    std::cout << a.getHitPoints() << std::endl;
    std::cout << a.getEnergyPoints() << std::endl;
    std::cout << a.getAttackDamage() << std::endl;
    a.attack("Alexis");
    a.whoAmI();
    return 0;
}