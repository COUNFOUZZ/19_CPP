#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class   Animal {
    protected:
        std::string _type;

    public:
        Animal(void);
        Animal(Animal const& other);
        Animal(std::string const type);
        virtual	~Animal(void);

        Animal &operator=(Animal const& dest);

        std::string		getType(void) const;
        virtual void    makeSound(void) const = 0;
};


#endif