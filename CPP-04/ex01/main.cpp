#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete i;
        delete j;
    }
    std::cout << std::endl << std::endl;
    {
        Dog bob;
        Cat bib;

        bob.setNewIdea(10, "I love steack");
        bob.getIdea(-9);
        bob.getIdea(10);
        std::cout << std::endl;
        bob.setNewIdea(98, "The water outdoor are terrible to drink !");
        bob.getIdea();

        std::cout << std::endl << std::endl;

        bib.setNewIdea(10, "I love catisfaction !");
        bib.getIdea(-9);
        bib.getIdea(10);
        std::cout << std::endl;
        bib.setNewIdea(98, "I love my owner");
        bib.getIdea();
    }
    system("leaks Brain");
    return 0;
}