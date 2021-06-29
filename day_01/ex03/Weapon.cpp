#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType(void) const
{
	return (this->type);
}

#include <iostream>

void		Weapon::setType(std::string type)
{
	this->type = type;
}
