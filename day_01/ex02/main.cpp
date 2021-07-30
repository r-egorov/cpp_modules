#include <iostream>
#include <string>

int		main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string		&stringREF = string;

	std::cout << "Printing addresses" << std::endl;
	std::cout << "&string:\t|" << &string << "|" << std::endl;
	std::cout << "stringPTR:\t|" << stringPTR << "|" << std::endl;
	std::cout << "&stringREF:\t|" << &stringREF << "|" << std::endl;

	std::cout << "Printing the value" << std::endl;
	std::cout << "string:\t\t|" << string << "|" << std::endl;
	std::cout << "*stringPTR:\t|" << *stringPTR << "|" << std::endl;
	std::cout << "stringREF:\t|" << stringREF << "|" << std::endl;
}
