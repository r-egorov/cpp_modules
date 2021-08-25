#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		*slots[4];
		void			init(void);
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &obj);
		~MateriaSource(void);
		MateriaSource	&operator=(const MateriaSource &obj);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

		void		show_slots(void);
};

#endif
