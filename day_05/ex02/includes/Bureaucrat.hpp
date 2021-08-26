#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat;
# include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const		name;
		int						grade;

	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		Bureaucrat				&operator = (Bureaucrat const &obj);

		std::string const		&getName(void) const;
		int						getGrade(void) const;

		void					incGrade(void);
		void					decGrade(void);
		void					signForm(Form &form);
		void					executeForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			const char	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char	*what(void) const throw();
		};
};

std::ostream	&operator << (std::ostream &o, Bureaucrat const &obj);

#endif
