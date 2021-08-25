#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(const Cure &obj)
{
	this->points = obj.points;
}

Cure		&Cure::operator=(const Cure &obj)
{
	this->points = obj.points;
	return (*this);
}

Cure		*Cure::clone(void) const
{
	Cure	*res = new Cure();
	return (res);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
