#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{
	private:
		void	puzzled(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Karen(void);
		~Karen(void);
		void	complain(std::string level);
};

#endif
