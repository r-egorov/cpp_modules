#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string			type;
		std::string			name;
		unsigned int			hp;
		unsigned int			ep;
		unsigned int			atk_dmg;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &obj);
		ClapTrap &operator=(const ClapTrap &obj);

		std::string	getName(void) const;
		unsigned int	getHp(void) const;
		unsigned int	getEp(void) const;
		unsigned int	getAtkDmg(void) const;

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
