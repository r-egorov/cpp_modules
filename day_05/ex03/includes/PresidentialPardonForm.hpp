#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>

class PresidentialPardonForm;
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	const			target;

	public:
		PresidentialPardonForm(void);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);

		PresidentialPardonForm	&operator = (PresidentialPardonForm const &obj);

		void					execute(Bureaucrat const &bur) const;
};

#endif
