#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class   WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const& other);
        WrongAnimal(std::string const& type);
        ~WrongAnimal(void);

        WrongAnimal&    operator=(WrongAnimal const& dest);

        std::string getType(void) const;
        void        makeSound(void) const;
};

#endif