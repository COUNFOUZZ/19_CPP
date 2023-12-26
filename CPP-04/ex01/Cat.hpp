#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal {
    private:
        Brain*  _brain;

    public:
        Cat(void);
        Cat(Cat const& other);
        ~Cat(void);

        Cat& operator=(Cat const& dest);

        void    makeSound(void) const;
        void    setNewIdea(int index, std::string str);
        void    getIdea(void) const;
        void    getIdea(int index) const;
};

#endif