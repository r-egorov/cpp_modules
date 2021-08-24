#include "Cat.hpp"

Cat::Cat(void)
{
	this->brain = new Brain("Cat idea");
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain();
	*this->brain = *obj.brain;
	this->type = obj.type;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignation operator called" << std::endl;
	*this->brain = *obj.brain;
	this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "\"Meeeeeeooooooooowww\", says the Cat." << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (brain);
}
