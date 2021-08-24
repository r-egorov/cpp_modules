#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain("Dog idea");
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this->brain = *obj.brain; 
	this->type = obj.type;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignation operator called" << std::endl;
	*this->brain = *obj.brain; 
	this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\"Bow-wow\", says the Dog." << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (brain);
}
