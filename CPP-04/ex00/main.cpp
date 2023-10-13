#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete  meta;
    delete  j;
    delete  i;

    //  Wrong part
    std::cout << std::endl << "===========================" << std::endl << std::endl;

    const   WrongAnimal* wrongmeta = new WrongAnimal();
    const   WrongAnimal* wrongcat = new WrongCat();

    std::cout << wrongmeta->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;

    wrongmeta->makeSound(); //will output the WrongAnimal sound!
    wrongcat->makeSound();  //will output the WrongAnimal sound!
    delete  wrongmeta;
    delete  wrongcat;
    return (0);
}