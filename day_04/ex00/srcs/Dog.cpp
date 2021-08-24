#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = obj.type;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\"Bow-wow\", says the Dog." << std::endl;
}
