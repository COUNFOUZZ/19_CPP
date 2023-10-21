#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain*  _brain;

    public:
        Dog(void);
        Dog(Dog const& other); 
        Dog& operator=(Dog const& other);
        ~Dog(void);
        void    makeSound(void) const;
        void    createIdeasRange(int start, int end, std::string idea);
        void    showIdeasZeroToNb(int nb) const;
};

#endif