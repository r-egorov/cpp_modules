#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif
