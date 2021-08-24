#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(const AMateria &obj)
{
	this->points = obj.points;
}

AMateria			&AMateria::operator=(const AMateria &obj)
{
	this->points = obj.points;
	return (*this);
}

void				AMateria::use(void) {}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}
