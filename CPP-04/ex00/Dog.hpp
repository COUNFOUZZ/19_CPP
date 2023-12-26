#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    private:

    public:
        Dog(void);
        Dog(Dog const& other);
        ~Dog(void);

        Dog& operator=(Dog const& dest);

        void    makeSound(void) const;
};

#endif