#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = obj.type;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	// std::cerr << "Error: base class can't make sounds" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
