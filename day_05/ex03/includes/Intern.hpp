#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <locale>

class Intern;
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &obj);

		Intern		&operator = (Intern const &obj);

		Form		*makeForm(std::string const &form, std::string const &target);

		class FormNotFoundException : public std::exception
		{
			const char		*what(void) const throw();
		};
};

#endif
