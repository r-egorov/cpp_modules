#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	ScavTrap : public ClapTrap
{
	private:
		static const std::string		type;
	public:
		ScavTrap(void);
		ScavTrap(std::string to_be_name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);
		ScavTrap &operator=(const ScavTrap &obj);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate(void);
};

#endif
