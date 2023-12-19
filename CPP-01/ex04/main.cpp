#include <iostream>
#include <fstream>

std::string replace(std::string src, const std::string s1, const std::string s2) {
    size_t pos(0);

    while ((pos = src.find(s1, pos)) != std::string::npos) {
        src = src.substr(0, pos) + s2 + src.substr(pos + s1.length());
        pos += s2.length();
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