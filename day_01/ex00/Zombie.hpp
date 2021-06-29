#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

		void	announce(void);
};

#endif
