#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		std::string input;

		for (int i = 1; i < argc ; ++i) {
			input = argv[i];
			for (int j = 0; j < (int)input.size(); ++j)
				std::cout << (char)toupper(input[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}