#include "./ScavTrap.hpp"

int main(void) {
{
		ClapTrap	john;

		std::cout << "Info of John the ClapTrap" << std::endl;
		john.getAllValue();
		john.attack("an other bad guy");
		john.takeDamage(4);
		john.beRepaired(2);

		std::cout << std::endl << std::endl;

		ClapTrap	bob("Bob");

		std::cout << "Info of Bob the ClapTrap" << std::endl;
		bob.getAllValue();
		bob.attack("a bad guy");
		bob.takeDamage(4);
		bob.beRepaired(2);

		std::cout << std::endl << std::endl;

		ClapTrap	cp_bob;

		cp_bob = bob;

		std::cout << "Info of cp_Bob the ClapTrap" << std::endl;
		cp_bob.getAllValue();
		cp_bob.attack("an other and other bad guy");
		cp_bob.takeDamage(4);
		cp_bob.beRepaired(2);
	}
	std::cout << std::endl << std::endl;
												// ********** ScavTrap ********** //
	{
		ScavTrap	john;

		std::cout << "Info of John the ScavTrap" << std::endl;
		john.getAllValue();
		john.attack("an other bad guy");
		john.takeDamage(4);
		john.beRepaired(2);
		john.guardGate();

		std::cout << std::endl << std::endl;

		ScavTrap	bob("Bob");

		std::cout << "Info of Bob the ScavTrap" << std::endl;
		bob.getAllValue();
		bob.attack("a bad guy");
		bob.takeDamage(4);
		bob.beRepaired(2);
		bob.guardGate();

		std::cout << std::endl << std::endl;

		ScavTrap	cp_bob;

		cp_bob = bob;

		std::cout << "Info of cp_Bob the ScavTrap" << std::endl;
		cp_bob.getAllValue();
		cp_bob.attack("an other and other bad guy");
		cp_bob.takeDamage(4);
		cp_bob.beRepaired(2);
		cp_bob.guardGate();
	}

    return 0;
}