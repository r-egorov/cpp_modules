#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		name;
		const Weapon 	&weapon;

	public:
		HumanA(std::string const &name, Weapon const &weapon);
		~HumanA(void);

		void	attack(void);
};

#endif
