#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	ScavTrap : public ClapTrap
{
	private:
		std::string		type = "ScavTrap";
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
