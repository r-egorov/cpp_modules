#include "Ice.hpp"
#include "Cure.hpp"

int		main(void)
{
	Ice		*ice = new Ice();

	ice->use();
	std::cout << ice->getType() << std::endl;

	Ice		*ice2 = ice->clone();

	ice2->use();
	std::cout << ice->getType() << std::endl;

	delete ice;
	delete ice2;
	
	Cure		*cure = new Cure();

	cure->use();
	std::cout << cure->getType() << std::endl;

	Cure		*cure2 = cure->clone();

	cure2->use();
	std::cout << cure->getType() << std::endl;

	delete cure;
	delete cure2;

}
