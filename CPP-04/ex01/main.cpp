#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
    // Animal* animals[] = {
    //     new Cat(),
    //     new Dog(),
    //     NULL
    // };

    // animals[0]->createIdeasRange(0, 99, "I'm a cat");
    // animals[1]->createIdeasRange(0, 99, "I'm a dog");
    // animals[0]->showIdeasZeroToNb(100);
    // std::cout << std::endl << std::endl;
    // animals[1]->showIdeasZeroToNb(100);

    // for (int i = 0; animals[i]; ++i)
    //     delete animals[i];

    Animal* animalCat = new Cat();
    Animal* animalCat2 = new Cat();

    std::cout << "[========================]" << std::endl;
    animalCat->createIdeasRange(0, 10, "I'm a cat");
    animalCat->showIdeasZeroToNb(20);
    std::cout << std::endl << "[------------------------]" << std::endl;
    animalCat2->showIdeasZeroToNb(20);
    std::cout << "[========================]" << std::endl;
    *animalCat2 = *animalCat;
    std::cout << "[========================]" << std::endl;
    animalCat2->showIdeasZeroToNb(20);
    std::cout << std::endl << "[------------------------]" << std::endl;
    animalCat->showIdeasZeroToNb(20);
    std::cout << "[========================]" << std::endl;
    return (0);
}