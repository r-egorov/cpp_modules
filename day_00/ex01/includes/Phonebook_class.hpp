#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"

class Phonebook
{
	private:
		Contact		contacts[8];
		int			index;

	public:
		Phonebook()
		{
			this->index = 0;
		}
		void		add(Contact contact);
		Contact*	search(void);
};

#endif
