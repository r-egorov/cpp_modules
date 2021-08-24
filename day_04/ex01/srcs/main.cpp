#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal	*zoo[40];

	for (int i = 0; i < 40; i++)
	{
		if (i < 20)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}

	for (int i = 0; i < 40; i++)
	{
		delete zoo[i];
	}

	Dog		*dog1 = new Dog();
	Dog		*dog2 = new Dog();

	std::cout << "Testing deep copies" << std::endl;
	std::cout << "Dog1: " << dog1->getBrain() << std::endl;
	std::cout << "Dog2: " << dog2->getBrain() << std::endl;


	Dog		dog_stack1;
	Dog		dog_stack2 = dog_stack1;
	std::cout << "Testing deep copies" << std::endl;
	std::cout << "Dog1: " << dog_stack1.getBrain() << std::endl;
	std::cout << "Dog2: " << dog_stack2.getBrain() << std::endl;

	std::string	*ideas1 = dog_stack1.getBrain()->getIdeas();
	std::string	*ideas2 = dog_stack2.getBrain()->getIdeas();

	for (int i = 0; i < 100; i++)
	{
		if (&(ideas1[i]) == &(ideas2[i]))
			std::cerr << "ERROR!!! NOT DEEP COPIES" << std::endl;
	}

	delete dog1;
	delete dog2;

	return (0);
}
