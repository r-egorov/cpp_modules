#include "Karen.hpp"
#include <iostream>
#include <cstring>

static char	*cstring_upper(char *s)
{
	for (size_t i = 0; i < std::strlen(s); i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] = s[i] - 32; 
	}
	return (s);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You talk too much! I want to hear only one word!" 
			<< std::endl;
		return (1);
	}
	Karen		karen;

	karen.complain(cstring_upper(argv[1]));
	return (0);
}
