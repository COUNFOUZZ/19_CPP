#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(FragTrap const & other);
        FragTrap(std::string const & name);
        FragTrap& operator=(FragTrap const & other);
        ~FragTrap(void);
        void    highFivesGuys(void) const;
};

#endif