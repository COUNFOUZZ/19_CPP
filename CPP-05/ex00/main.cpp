#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat  bob("Bob");

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

    return 0;
}