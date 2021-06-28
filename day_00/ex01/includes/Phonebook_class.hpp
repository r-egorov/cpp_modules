#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"

class Phonebook
{
	private:
		Contact		contacts[8];
		int			count;
		int			index;

	public:
		Phonebook();

		int			get_count(void);
		void		add(Contact contact);
		Contact		search(int index);
};

#endif
