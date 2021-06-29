#include "HumanA.hpp"

HumanA::~HumanA(void) {}

HumanA::HumanA(std::string const &name, Weapon const &weapon) :
	name(name), weapon(weapon) {}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType()
		<< std::endl;
}
