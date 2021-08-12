#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	def_scav;
	ScavTrap	par_scav("Bob");
	ScavTrap	cp_scav(par_scav);

	std::cout
		<< "Default ScavTrap's name is "
		<< def_scav.getName()
		<< std::endl;

	std::cout
		<< "Parametrized ScavTrap's name is "
		<< par_scav.getName()
		<< std::endl;

	std::cout
		<< "Copied ScavTrap's name is "
		<< cp_scav.getName()
		<< std::endl;

	par_scav.attack("Selena");
	par_scav.takeDamage(20);

	std::cout
		<< par_scav.getName() << "'s HP = "
		<< par_scav.getHp()
		<< std::endl;

	par_scav.beRepaired(10);

	std::cout
		<< par_scav.getName() << "'s HP = "
		<< par_scav.getHp()
		<< std::endl;

	par_scav.guardGate();

	ScavTrap	as_scav("Thomas");

	as_scav = par_scav;
	std::cout
		<< "Thomas's name after assignation is "
		<< as_scav.getName()
		<< ", his HP = "
		<< as_scav.getHp()
		<< std::endl;
}
