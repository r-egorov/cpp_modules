#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		const Weapon 	*weapon;

	public:
		HumanB(std::string const &name);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
