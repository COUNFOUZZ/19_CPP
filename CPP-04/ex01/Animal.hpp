#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal(void);
        Animal(Animal const& other); 
        Animal& operator=(Animal const& other);
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void    makeSound(void) const;
        virtual void    createIdeasRange(int start, int end, std::string idea) = 0;
        virtual void    showIdeasZeroToNb(int nb) const = 0;
};

#endif