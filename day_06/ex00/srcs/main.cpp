#include "Converter.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERROR: The program takes one argument" << std::endl;
		return (1);
	}

	Converter		conv;

	conv.convert(argv[1]);
}
