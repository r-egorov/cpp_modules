#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Form;
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string	const	name;
		bool				isSigned;
		int			const	signGrade;
		int			const	execGrade;
	public:
		Form(void);
		virtual ~Form(void);
		Form(std::string name, int const signGrade, int const execGrade);
		Form(Form const &obj);

		Form				&operator = (Form const &obj);

		std::string const	&getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				wasSigned(void) const;

		void				beSigned(Bureaucrat const &b);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooLowException : public std::exception
		{
			const char		*what(void) const throw();
		};
		class GradeTooHighException : public std::exception
		{
			const char		*what(void) const throw();
		};
		class NotSignedException : public std::exception
		{
			const char		*what(void) const throw();
		};
		class AlreadySignedException : public std::exception
		{
			const char		*what(void) const throw();
		};
};

std::ostream	&operator << (std::ostream &o, Form const &obj);

#endif
