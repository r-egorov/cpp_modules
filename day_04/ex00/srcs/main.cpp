#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal*	wr_animal = new WrongCat();
	const WrongCat*		wr_cat = new WrongCat();

	std::cout << "<" << wr_animal->getType() << ">" << std::endl;
	wr_animal->makeSound();
	std::cout << "<" << wr_cat->getType() << ">" << std::endl;
	wr_cat->makeSound();

	delete wr_animal;
	delete wr_cat;

	const Animal	*zoo[3] = {meta, j, i};

	for(int i = 0; i < 3; i++)
	{
		std::cout << "Animal type: <" << zoo[i]->getType() << ">" << std::endl;
		zoo[i]->makeSound();
	}

	for(int i = 0; i < 3; i++)
	{
		delete zoo[i];
	}

	return (0);
}
