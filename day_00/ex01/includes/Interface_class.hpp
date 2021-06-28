#ifndef INTERFACE_CLASS_HPP
# define INTERFACE_CLASS_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# define FRED(x) RED x
# define FGREEN(x) GREEN x
# define FYELLOW(x) YELLOW x
# define FRESET(x) x RESET


# include <string>
# include <iostream>

# include "Contact_class.hpp"
# include "Phonebook_class.hpp"

class	Interface
{
	private:
		Phonebook	phonebook;
		std::string	input;

	public:
		void	run(void);
		void	stop(void);
		void	add(void);
		void	search(void);
};

#endif
