#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact(void);
		Contact(const Contact &other);

		Contact& operator= (const Contact &other);
		
		void		entry_print(void);
		void		full_print(void);

		void		set_first_name(std::string first_name);
		std::string get_first_name(void) const;

		void		set_last_name(std::string last_name);
		std::string get_last_name(void) const;

		void		set_nickname(std::string nickname);
		std::string get_nickname(void) const;

		void		set_phone_number(std::string phone_number);
		std::string get_phone_number(void) const;
		
		void		set_darkest_secret(std::string darkest_secret);
		std::string get_darkest_secret(void) const;
};

#endif
