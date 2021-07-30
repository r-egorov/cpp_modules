#include "Karen.hpp"
#include <iostream>

Karen::Karen(void) {}

Karen::~Karen(void) {}

void		Karen::puzzled(void)
{
	std::cerr << "I don't understand what you want from me! "
		<< "Leave me alone!" << std::endl;
}

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
	std::cerr << "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

void		Karen::complain(std::string level)
{
	typedef void		(Karen::*comment)(void);
	static comment		comments[5] =
	{
		&Karen::puzzled,
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};

	int	index;

	index = (!level.compare("DEBUG")) * 1
		+ (!level.compare("INFO")) * 2
		+ (!level.compare("WARNING")) * 3
		+ (!level.compare("ERROR")) * 4;

	(this->*comments[index])();
}
