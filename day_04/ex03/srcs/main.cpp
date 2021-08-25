#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int		main(void)
{
	std::string	tom_name("Thomas");
	std::string	andy_name("Andrew");

	Character	*tom = new Character(tom_name);
	Character	*andy = new Character(andy_name);
	MateriaSource *source = new MateriaSource();

	source->show_slots();

	Cure		*cure = new Cure();
	Ice		*ice = new Ice();

	source->learnMateria(ice);
	source->learnMateria(cure);
	source->show_slots();

	tom->equip(ice);
	tom->equip(source->createMateria("cure"));
	tom->show_inv();
	tom->use(0, *andy);

	Character	*tom_copy = tom;

	tom_copy->equip(cure);
	tom->equip(source->createMateria("ice"));
	tom->show_inv();
	tom_copy->use(1, *andy);

	delete tom;
	delete andy;
	delete source;
	return (0);
}


/*
int		main(void)
{
	IMateriaSource		*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter			*me = new Character("me");
	AMateria			*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter			*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
*/
