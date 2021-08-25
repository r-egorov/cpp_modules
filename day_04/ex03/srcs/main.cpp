#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int		main(void)
{
	std::string	tom_name("Thomas");
	std::string	andy_name("Thomas");

	Character	*tom = new Character(tom_name);
	Character	*andy = new Character(andy_name);

	Ice		*ice = new Ice();

	tom->equip(ice);
	tom->use(0, *andy);

	Character	*tom_copy = tom;

	Cure		*cure = new Cure();

	tom_copy->equip(cure);
	tom_copy->use(1, *andy);

	delete tom;
	delete andy;
}
