#include <iostream>
#include <fstream>

std::string	replace(std::string src, std::string s1, std::string s2) {
	size_t len = src.length();

	for (size_t i = 0; i < len; ++i) {
		if (src.compare(i, s1.length(), s1) == 0) {
			src.erase(i, s1.length());
			src.insert(i, s2);
		}
	}
	return (src);
}

int	main(int argc, char **argv) {
	if (argc != 4)
		return (std::cerr << "Invalid number of paramater !" << std::endl, 1);
	std::string		filename(argv[1]);
	std::ifstream	infile(filename.c_str());
	std::string		toReplace(argv[2]);
	std::string		replaceBy(argv[3]);

	if (!infile.is_open())
		return (std::cerr << "Error, file doesn't exist !" << std::endl, 2);

	std::ofstream	outfile((filename + ".replace").c_str());
	std::string		line;

	for (;getline(infile, line);) {
		outfile << replace(line, toReplace, replaceBy);
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}