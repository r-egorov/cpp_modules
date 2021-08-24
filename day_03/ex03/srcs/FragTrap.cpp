#include "FragTrap.hpp"

const std::string	FragTrap::type = "FragTrap";

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	this->hp = 100;
	this->ep = 100;
	this->atk_dmg = 30;
	std::cout
		<< "A default "
		<< this->type
		<< " constructor was called"
		<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->atk_dmg = 30;
	std::cout 
		<< "A parametrized "
		<< this->type
		<< " constructor was called " 
		<< "with the name `"
		<< this->name
		<< "`"
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout
		<< "A "
		<< this->type
		<< " copy constructor was called"
		<< std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout
		<< "A "
		<< this->type
		<< " assignation operator was called"
		<< std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "A " << this->type
		<< " destructor was called" << std::endl;
}

void		FragTrap::attack(std::string const &target)
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

void		FragTrap::takeDamage(unsigned int amount)
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

void		FragTrap::beRepaired(unsigned int amount)
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

void		FragTrap::highFivesGuys(void)
{

	std::cout
		<< "[" << this->type << " <"
		<< this->name << ">]: "
		<< "`High fives, guys!`"
		<< std::endl;
}
