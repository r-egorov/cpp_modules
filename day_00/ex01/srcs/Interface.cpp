#include "Interface_class.hpp"

void	Interface::run(void)
{
	std::cout << "Welcome to `Awesome PhoneBook v1.0`" << std::endl
		<< "Please, enter a command below." << std::endl;
	while (std::getline(std::cin, input))
	{
		std::transform(
				input.begin(), input.end(), input.begin(), tolower);
		if (input == "exit")
			break ;
		else if (input == "add")
			this->add();
		else if (input == "search")
			this->search();
		else
			std::cout << "Invalid command. Try again." << std::endl;
	}
	this->stop();
}

void	Interface::stop(void)
{
	std::cout << "Thank you for choosing `Awesome PhoneBook v1.0`" << std::endl
		<< "Bye-bye!" << std::endl;
}

void	Interface::add(void)
{
	std::cout << "COMMAND ADD TRIGGERED" << std::endl;
}

void	Interface::search(void)
{
	std::cout << "COMMAND SEARCH TRIGGERED" << std::endl;
}
