#include "Contact_class.hpp"

void		Contact::entry_print(void)
{
	std::string		iter[3] =
	{
		this->get_first_name(),
		this->get_last_name(),
		this->get_nickname(),
	};
	std::string			buffer;
	unsigned long		buflen;
	std::string			print = "";

	for (int i = 0; i < 3; i++)
	{	
		buffer = iter[i].substr(0, 9);
		buflen = buffer.length();
		if (buflen < 9)
		{
			for (unsigned long j = 0; j < 10 - buflen; j++)
				buffer += " ";
		}
		else
		{
			buffer += ".";
		}
		buffer += "|";
		print += buffer;
	}
	std::cout << print << std::endl;
}

void		Contact::full_print(void)
{
	std::cout
		<< "First name:\t| " << this->get_first_name() << "\n"
		<< "Last name:\t| " << this->get_last_name() << "\n"
		<< "Nickname:\t| " << this->get_nickname() << "\n"
		<< "Phone number:\t| " << this->get_phone_number() << "\n"
		<< "Darkest secret:\t| " << this->get_darkest_secret() << std::endl;
}

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::Contact(const Contact &other)
{
	this->first_name = other.get_first_name();
	this->last_name = other.get_last_name();
	this->nickname = other.get_nickname();
	this->phone_number = other.get_phone_number();
	this->darkest_secret = other.get_darkest_secret();
}

void				Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

std::string Contact::get_first_name(void) const
{
	return (this->first_name);
}

void				Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

std::string Contact::get_last_name(void) const
{
	return (this->last_name);
}

void				Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::get_nickname(void) const
{
	return (this->nickname);
}

void				Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

std::string Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

void				Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}

Contact& Contact::operator= (const Contact &other)
{
	first_name = other.get_first_name();
	last_name = other.get_last_name();
	nickname = other.get_nickname();
	phone_number = other.get_phone_number();
	darkest_secret = other.get_darkest_secret();

	return (*this);
}

