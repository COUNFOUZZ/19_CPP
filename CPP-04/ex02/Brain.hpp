#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class   Brain {
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(Brain const& other);
        ~Brain(void);

        Brain&  operator=(Brain const& dest);

        void    setNewIdea(int index, std::string str);
        void    getIdea(void) const;
        void    getIdea(int index) const;
};

#endif