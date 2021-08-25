#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inv[4];

		void				init(void);
	public:
		Character(void);
		Character(std::string &name);
		~Character(void);
		Character(const Character &obj);
		Character			&operator=(const Character &obj);

		std::string const	&getName(void) const;

		void				equip(AMateria *m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter &target);
};

#endif
