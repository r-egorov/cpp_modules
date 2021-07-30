#include "Karen.hpp"
#include <iostream>

Karen::Karen(void) {}

Karen::~Karen(void) {}

void		Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my "
	       << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	       << "I just love it!"
	       << std::endl;
}

void		Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
		<< "You don’t put enough! "
		<< "If you did I would not have to ask for it!"
		<< std::endl;
}

void		Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming here for years "
		<< "and you just started working here last month."
		<< std::endl;
}

void		Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

void		Karen::complain(std::string level)
{
	typedef void		(Karen::*comment)(void);
	static comment		comments[4] =
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};
	static std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
		{
			(this->*comments[i])();
			return ;
		}
	}

	std::cerr << "I don't understand what you want from me! "
		<< "Leave me alone!" << std::endl;
}
