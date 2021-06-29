#include "HumanB.hpp"

HumanB::~HumanB(void) {}

HumanB::HumanB(std::string const &name) :
	name(name)
{
	this->weapon = NULL;
}

void	HumanB::attack(void)
{
	std::string		weapon;

	if (!this->weapon)
		weapon = "bare hands";
	else
		weapon = this->weapon->getType();

	std::cout << this->name << " attacks with his " << weapon << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
