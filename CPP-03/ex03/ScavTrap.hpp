#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(ScavTrap const & other);
        ScavTrap(std::string const & name);
        ScavTrap& operator=(ScavTrap const & other);
        ~ScavTrap(void);
        void    attack(const std::string& target);
        void    guardGate(void) const;
};

#endif