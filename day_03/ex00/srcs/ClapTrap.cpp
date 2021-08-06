#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : name("Claptrap")
{
	std::cout << "A default ClapTrap constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string to_be_name) : name(to_be_name)
{
	std::cout 
		<< "A parametrized ClapTrap constructor was called " 
		<< "with the name `"
		<< this->name
		<< "`"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "A ClapTrap copy constructor was called" << std::endl;
	this->name = obj.getName();
	this->ep = obj.getEp();
	this->hp = obj.getHp();
	this->atk_dmg = obj.getAtkDmg();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "A ClapTrap destructor was called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "A ClapTrap assignation operator was called" << std::endl;
	this->name = obj.getName();
	this->ep = obj.getEp();
	this->hp = obj.getHp();
	this->atk_dmg = obj.getAtkDmg();
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHp(void) const
{
	return (this->hp);
}

unsigned int	ClapTrap::getEp(void) const
{
	return (this->ep);
}

unsigned int	ClapTrap::getAtkDmg(void) const
{
	return (this->atk_dmg);
}

void		ClapTrap::attack(std::string const &target)
{
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->atk_dmg
		<< " points of damage!"
		<< std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->hp -= amount;
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " takes "
		<< amount
		<< " points of damage!"
		<< std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->hp += amount;
	std::cout
		<< "ClapTrap "
		<< this->name
		<< " repaires! "
		<< amount
		<< " hit points restored!"
		<< std::endl;
}
