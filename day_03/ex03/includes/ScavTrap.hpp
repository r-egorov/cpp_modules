#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	ScavTrap : virtual public ClapTrap
{
	private:
		std::string		type = "ScavTrap";
	protected:
		const static unsigned int	default_hp = 100;
		const static unsigned int	default_ep = 50;
		const static unsigned int	default_atk_dmg = 20;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);
		ScavTrap &operator=(const ScavTrap &obj);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate(void);
};

#endif
