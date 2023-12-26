#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class   Cat : public Animal {
    private:

    public:
    Cat(void);
    Cat(Cat const& other);
    ~Cat(void);

    Cat& operator=(Cat const& dest);

    void    makeSound(void) const;
};

#endif