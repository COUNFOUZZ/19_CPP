#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain*  _brain;

    public:
        Cat(void);
        Cat(Cat const& other); 
        Cat& operator=(Cat const& other);
        ~Cat(void);
        void    makeSound(void) const;
        void    createIdeasRange(int start, int end, std::string idea);
        void    showIdeasZeroToNb(int nb) const;
};

#endif