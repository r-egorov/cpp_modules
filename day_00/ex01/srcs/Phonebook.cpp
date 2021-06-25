#include "Phonebook_class.hpp"

void	Phonebook::add(Contact contact)
{
	if (this->index < 8)
	{
		this->contacts[this->index] = contact;
	}
	else
	{
		this->index = 0;
		this->add(contact);
	}
}

Contact*	Phonebook::search(void)
{
	return (this->contacts);
}
