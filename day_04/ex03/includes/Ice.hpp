#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &obj);
		Ice &operator=(const Ice &obj);

		Ice*		clone(void) const;
		void		use(void);
		//void		use(ICharacter &target);
};

#endif
