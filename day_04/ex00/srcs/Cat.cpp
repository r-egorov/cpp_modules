#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = obj.type;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "\"Meeeeeeooooooooowww\", says the Cat." << std::endl;
}
