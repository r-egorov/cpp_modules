#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Claptrap")
{
	this->hp = 10;
	this->ep = 10;
	this->atk_dmg = 0;
	std::cout 
		<< "A default "
		<< this->type
		<< " constructor was called"
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	this->hp = 10;
	this->ep = 10;
	this->atk_dmg = 0;
	std::cout 
		<< "A parametrized ClapTrap constructor was called "
		<< "with the name `"
		<< this->name
		<< "`"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "A "
	       << this->type
	       << " copy constructor was called" << std::endl;
	this->name = obj.getName();
	this->ep = obj.getEp();
	this->hp = obj.getHp();
	this->atk_dmg = obj.getAtkDmg();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "A " << this->type << " destructor was called"
		<< std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout
		<< "A " << this->type
		<< " assignation operator was called" << std::endl;
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
		<< this->type << " "
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
		<< this->type << " "
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
		<< this->type << " "
		<< this->name
		<< " repaires! "
		<< amount
		<< " hit points restored!"
		<< std::endl;
}
