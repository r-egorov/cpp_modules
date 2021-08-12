#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	FragTrap : public ClapTrap
{
	private:
		std::string		type = "FragTrap";
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap &obj);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
