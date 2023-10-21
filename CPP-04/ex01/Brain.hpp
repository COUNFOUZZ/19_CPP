#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(Brain const& other); 
        Brain& operator=(Brain const& other);
        ~Brain(void);
        std::string getIdeas(int index) const;
        void        setIdeas(int index, std::string const ideas);
};

#endif