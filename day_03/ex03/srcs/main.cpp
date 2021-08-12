#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	diamond_def;
	DiamondTrap	diamond("Thomas");

	std::cout
		<< "HP = " << diamond.getHp() << " "
		<< "EP = " << diamond.getEp() << " "
		<< "ATK = " << diamond.getAtkDmg() << " "
		<< std::endl;
	diamond.whoAmI();
	diamond.attack("Somebody");
	diamond.guardGate();
	diamond.highFivesGuys();

	DiamondTrap	new_tom(diamond);
	new_tom.whoAmI();
	std::cout
		<< "HP = " << new_tom.getHp() << " "
		<< "EP = " << new_tom.getEp() << " "
		<< "ATK = " << new_tom.getAtkDmg() << " "
		<< std::endl;
	new_tom.takeDamage(50);
	std::cout
		<< "HP = " << new_tom.getHp() << " "
		<< std::endl;

	DiamondTrap	fresh("Fresh");
	new_tom = fresh;
	std::cout
		<< "HP = " << new_tom.getHp() << " "
		<< "EP = " << new_tom.getEp() << " "
		<< "ATK = " << new_tom.getAtkDmg() << " "
		<< std::endl;
}
