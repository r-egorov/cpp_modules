#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(const Ice &obj)
{
	this->points = obj.points;
}

Ice		&Ice::operator=(const Ice &obj)
{
	this->points = obj.points;
	return (*this);
}

Ice		*Ice::clone(void) const
{
	Ice	*res = new Ice();
	return (res);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
