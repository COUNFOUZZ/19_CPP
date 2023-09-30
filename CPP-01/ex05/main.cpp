#include "./Harl.hpp"

int	main(void) {
	Harl	instance;

	instance.complain("DEBUG");
	instance.complain("debug");
	instance.complain("INFO");
	instance.complain("info");
	instance.complain("WARNING");
	instance.complain("warning");
	instance.complain("ERROR");
	instance.complain("error");
	instance.complain("hello");

	return (0);
}