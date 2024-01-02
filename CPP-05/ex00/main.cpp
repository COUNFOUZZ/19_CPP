#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat  bob("Bob", 10);

        std::cout << bob << std::endl;
        bob.demote();
        std::cout << bob << std::endl;
        bob.promote();
        bob.promote();
        std::cout << bob << std::endl;
        bob.demote();

        std::cout << std::endl << "bobby part:" << std::endl << std::endl;
        Bureaucrat  bobby(bob);

        std::cout << bob << std::endl;
        bob.demote();
        std::cout << bob << std::endl;
        bob.promote();
        bob.promote();
        std::cout << bob << std::endl;
        bob.demote();

        std::cout << std::endl << "bobbob part:" << std::endl << std::endl;
        Bureaucrat  bobbob = bobby;

        std::cout << bobbob << std::endl;
        for (int i = 0; i < 10; ++i)
            bobbob.demote();
        for (int i = 0; i < 20; ++i)
            bobbob.promote();
        
        Bureaucrat  elPatron("President", 1);
        
        std::cout << elPatron << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}