#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie*	zombieHorde(int N, std::string name);

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage:\n" << "./horde num_zombies_in_horde name" << std::endl;
		return (0);
	}
	else if (argc != 3)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}

	int N = std::atoi(argv[1]);

	if (N < 1)
	{
		std::cerr << "Invalid N argument, must be greater than 0" << std::endl;
		return (2);
	}

	Zombie		*horde;
	std::string	name = argv[2];

	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}
