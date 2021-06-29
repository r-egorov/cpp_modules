#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->name << "> [destroyed]" << std::endl;
}

void		Zombie::announce(void)
{
	std::cout << "<" << this->name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void		Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName(void) const
{
	return (this->name);
}
