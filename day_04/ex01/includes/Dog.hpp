#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif
