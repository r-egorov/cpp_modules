#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(std::string idea)
{
	std::cout
		<< "Brain constructor called with idea <"
		<< idea << ">"
		<< std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = idea;
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	delete [] this->ideas;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
}

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

std::string	*Brain::getIdeas(void) const
{
	return (this->ideas);
}
