#include "Phonebook_class.hpp"

Phonebook::Phonebook(void)
{
	this->index = 0;
	this->count = 0;
}

void	Phonebook::add(Contact contact)
{
	if (this->index < 8)
	{
		this->contacts[this->index] = contact;
		this->index += 1;
		this->count += 1;
	}
	else
	{
		this->index = 0;
		this->add(contact);
	}
}

int		Phonebook::get_count(void)
{
	return (this->count);
}

Contact	Phonebook::search(int i)
{
	return (this->contacts[i]);
}
