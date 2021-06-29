#include "Zombie.hpp"

Zombie*	newZombie(std::string name);

void	randomChump(std::string name)
{
	Zombie*	chump;

	chump = newZombie(name);
	chump->announce();

	delete chump;
}
