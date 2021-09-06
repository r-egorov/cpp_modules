#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure(const Cure &obj);
		Cure &operator=(const Cure &obj);

		Cure*		clone(void) const;
		void		use(ICharacter &target);
};

#endif
