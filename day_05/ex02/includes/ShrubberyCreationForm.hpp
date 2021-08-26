#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

class ShrubberyCreationForm;
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	const			target;
		std::string static const	trees[3];

	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);

		ShrubberyCreationForm	&operator = (ShrubberyCreationForm const &obj);

		void					execute(Bureaucrat const &bur) const;

		class FailedToOpenException : public std::exception
		{
			const char		*what(void) const throw();
		};
		class FailedToWriteException : public std::exception
		{
			const char		*what(void) const throw();
		};
};

#endif
