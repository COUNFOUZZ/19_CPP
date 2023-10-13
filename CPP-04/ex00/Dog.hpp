#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"

class Dog : public Animal {
    public:
        Dog(void);
        Dog(Dog const& other); 
        Dog& operator=(Dog const& other);
        ~Dog(void);
        void    makeSound(void) const;
};

#endif