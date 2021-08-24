#include "ScavTrap.hpp"

const std::string	ScavTrap::type = "ScavTrap";

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	this->hp = 100;
	this->ep = 50;
	this->atk_dmg = 20;
	std::cout
		<< "A default "
		<< this->type
		<< " constructor was called"
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->atk_dmg = 20;
	std::cout 
		<< "A parametrized "
		<< this->type
		<< " constructor was called " 
		<< "with the name `"
		<< this->name
		<< "`"
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout
		<< "A "
		<< this->type
		<< " copy constructor was called"
		<< std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout
		<< "A "
		<< this->type
		<< " assignation operator was called"
		<< std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "A " << this->type
		<< " destructor was called" << std::endl;
}

void		ScavTrap::attack(std::string const &target)
{
	std::cout
		<< this->type << " "
		<< this->name
		<< " attacks "
		<< target
		<< ", causing "
		<< this->getAtkDmg()
		<< " points of damage!"
		<< std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
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

void		ScavTrap::beRepaired(unsigned int amount)
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

void		ScavTrap::guardGate(void)
{
	std::cout
		<< this->type << " "
		<< this->name
		<< " has entered Gate keeper mode"
		<< std::endl;
}
