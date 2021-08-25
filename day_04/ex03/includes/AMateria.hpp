#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	const	type;
		int					points;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		virtual ~AMateria(void);
		AMateria(const AMateria &obj);
		AMateria &operator=(const AMateria &obj);

		std::string const	&getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
