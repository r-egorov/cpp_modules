#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(void);
		Weapon(std::string);
		~Weapon(void);

		std::string	getType(void) const;
		void		setType(std::string	type);
};

#endif
