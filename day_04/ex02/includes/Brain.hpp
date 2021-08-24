#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string		*ideas;
	public:
		Brain(void);
		Brain(std::string idea);
		~Brain(void);
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);

		std::string		*getIdeas(void) const;
};

#endif
