#include "Converter.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERROR] The program takes one argument" << std::endl;
		return (1);
	}

	Converter		conv;
	std::string		to_be_parsed(argv[1]);

	conv.convert(to_be_parsed);
}
