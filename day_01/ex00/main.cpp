#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int		main(void)
{
	Zombie brad("Brad");
	Zombie *holly;

	brad.announce();

	holly = newZombie("Holly");
	holly->announce();
	delete holly;

	randomChump("Thomas");
}
