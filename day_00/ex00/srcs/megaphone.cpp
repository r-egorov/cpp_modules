#include <iostream>
#include <string>

std::string	string_toupper(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), toupper);
	return (s);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		string_toupper(str);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
