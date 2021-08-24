#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	const Animal	*zoo[2] = {j, i};

	for(int i = 0; i < 2; i++)
	{
		std::cout << "Animal type: <" << zoo[i]->getType() << ">" << std::endl;
		zoo[i]->makeSound();
	}

	for(int i = 0; i < 2; i++)
	{
		delete zoo[i];
	}

	return (0);
}
