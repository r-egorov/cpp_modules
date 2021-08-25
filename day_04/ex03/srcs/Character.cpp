#include "Character.hpp"

void				Character::init(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->inv[i] = NULL;
	}
}

Character::Character(void)
{
	this->init();
}

Character::Character(std::string name) : name(name)
{
	this->init();
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inv[i];
	}
}

Character::Character(const Character &obj)
{
	this->name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
		{
			delete this->inv[i];
			this->inv[i] = NULL;
		}
		if (obj.inv[i])
			this->inv[i] = obj.inv[i]->clone();
	}
}

Character			&Character::operator=(const Character &obj)
{
	if (this == &obj)
		return (*this);

	this->name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
		{
			delete this->inv[i];
			this->inv[i] = NULL;
		}
		if (obj.inv[i])
			this->inv[i] = obj.inv[i]->clone();
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inv[i])
		{
			this->inv[i] = m;
			return ;
		}
	}
}

void				Character::unequip(int idx)
{
	if (this->inv[idx])
		this->inv[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (this->inv[idx])
	{
		this->inv[idx]->use(target);
	}
}

void				Character::show_inv(void)
{
	std::cout << "[" << this->getName() << "'s inventory]" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "|" << i << "| ";
		if (this->inv[i])
		{
			std::cout << this->inv[i]->getType() << ";" << std::endl;
		}
		else
		{
			std::cout << "NULL;" << std::endl;
		}
	}
}
