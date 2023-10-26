#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    public:
        DiamondTrap(void);
        DiamondTrap(DiamondTrap const & other);
        DiamondTrap(std::string const & name);
        DiamondTrap& operator=(DiamondTrap const & other);
        ~DiamondTrap(void);
        unsigned int    getHitPoints(void) const;
        unsigned int    getEnergyPoints(void) const;
        unsigned int    getAttackDamage(void) const;
        void            whoAmI(void) const;
};

#endif