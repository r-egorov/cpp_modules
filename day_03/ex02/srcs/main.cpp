#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap	def_frag;
	FragTrap	par_frag("Bob");
	FragTrap	cp_frag(par_frag);

	std::cout
		<< "Default FragTrap's name is "
		<< def_frag.getName()
		<< std::endl;

	std::cout
		<< "Parametrized FragTrap's name is "
		<< par_frag.getName()
		<< std::endl;

	std::cout
		<< "Copied FragTrap's name is "
		<< cp_frag.getName()
		<< std::endl;

	par_frag.attack("Selena");
	par_frag.takeDamage(20);

	std::cout
		<< par_frag.getName() << "'s HP = "
		<< par_frag.getHp()
		<< std::endl;

	par_frag.beRepaired(10);

	std::cout
		<< par_frag.getName() << "'s HP = "
		<< par_frag.getHp()
		<< std::endl;

	par_frag.highFivesGuys();

	FragTrap	as_frag("Thomas");

	as_frag = par_frag;
	std::cout
		<< "Thomas's name after assignation is "
		<< as_frag.getName()
		<< ", his HP = "
		<< as_frag.getHp()
		<< std::endl;
}
