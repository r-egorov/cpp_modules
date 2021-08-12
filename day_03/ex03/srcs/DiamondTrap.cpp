#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap("DiamondTrap__clap__name"),
	ScavTrap("DiamondTrap"),
	FragTrap("DiamondTrap")
{
	this->name = "DiamondTrap";
	this->hp = FragTrap::default_hp;
	this->ep = ScavTrap::default_ep;
	this->atk_dmg = FragTrap::default_atk_dmg;
	std::cout
		<< "A default "
		<< this->type
		<< " constructor was called"
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "__clap__name"),
	ScavTrap(name),
	FragTrap(name)
{
	this->name = name;
	this->hp = FragTrap::default_hp;
	this->ep = ScavTrap::default_ep;
	this->atk_dmg = FragTrap::default_atk_dmg;
	std::cout 
		<< "A parametrized "
		<< this->type
		<< " constructor was called " 
		<< "with the name `"
		<< this->name
		<< "`"
		<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) :
	ClapTrap(obj)
{
	this->name = obj.name;
	this->hp = obj.hp;
	this->ep = obj.ep;
	this->atk_dmg = obj.atk_dmg;
	std::cout
		<< "A "
		<< this->type
		<< " copy constructor was called"
		<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	ClapTrap::operator=(obj);
	this->name = obj.name;
	std::cout
		<< "A "
		<< this->type
		<< " assignation operator was called"
		<< std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "A " << this->type
		<< " destructor was called" << std::endl;
}

void		DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::takeDamage(unsigned int amount)
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

void		DiamondTrap::beRepaired(unsigned int amount)
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

void		DiamondTrap::whoAmI(void)
{
	std::cout
		<< this->type << "'s clap name is "
		<< ClapTrap::name << ". But his real name is "
		<< this->name << "."
		<< std::endl;
}
