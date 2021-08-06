#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	def_clap;
	ClapTrap	thomas("Thomas");
	ClapTrap	copy(thomas);

	std::cout
		<< "Default ClapTrap's name is "
		<< def_clap.getName()
		<<std::endl;

	def_clap = copy;

	std::cout
		<< "[After assignation]Default ClapTrap's name is "
		<< def_clap.getName()
		<<std::endl;

	thomas.attack("Handsome Jack");
	thomas.takeDamage(8);

	std::cout
		<< "Thomas's HP = "
		<< thomas.getHp()
		<<std::endl;

	thomas.beRepaired(5);
	std::cout
		<< "Thomas's HP = "
		<< thomas.getHp()
		<<std::endl;
}
