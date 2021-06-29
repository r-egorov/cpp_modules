#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

		void		announce(void);
		void		setName(std::string name);
		std::string	getName(void) const;
};

#endif
