#ifndef INTERFACE_CLASS_HPP
# define INTERFACE_CLASS_HPP

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
