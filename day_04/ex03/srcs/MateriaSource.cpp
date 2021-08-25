#include "MateriaSource.hpp"

void				MateriaSource::init(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->slots[i] = NULL;
	}
}

MateriaSource::MateriaSource(void)
{
	this->init();
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
		{
			delete this->slots[i];
			this->slots[i] = NULL;
		}
		if (obj.slots[i])
		{
			this->slots[i] = obj.slots[i]->clone();
		}
	}
}

MateriaSource		&MateriaSource::operator=(const MateriaSource &obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
		{
			delete this->slots[i];
			this->slots[i] = NULL;
		}
		if (obj.slots[i])
		{
			this->slots[i] = obj.slots[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
		{
			delete this->slots[i];
		}
	}
}

void				MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m->clone();
			return ;
		}
	}
}

AMateria			*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->slots[i]) && (this->slots[i]->getType() == type))
			return (this->slots[i]->clone());
	}
	return (NULL);
}

void				MateriaSource::show_slots(void)
{
	std::cout << "[Source slots]" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "|" << i << "| ";
		if (this->slots[i])
		{
			std::cout << this->slots[i]->getType() << ";" << std::endl;
		}
		else
		{
			std::cout << "NULL;" << std::endl;
		}
	}
}
