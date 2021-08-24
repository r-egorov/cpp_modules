#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	FragTrap : virtual public ClapTrap
{
	private:
		static const std::string			type;
	protected:
		const static unsigned int			default_hp = 100;
		const static unsigned int			default_ep = 100;
		const static unsigned int			default_atk_dmg = 30;
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
