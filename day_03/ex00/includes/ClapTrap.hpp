#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hp = 10;
		unsigned int	ep = 10;
		unsigned int	atk_dmg = 0;
	public:
		ClapTrap(void);
		ClapTrap(std::string to_be_name);
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
