#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		type = "DiamondTrap";
		std::string		name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap(void);
		DiamondTrap &operator=(const DiamondTrap &obj);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	whoAmI(void);
		void	info(void);
};

#endif
