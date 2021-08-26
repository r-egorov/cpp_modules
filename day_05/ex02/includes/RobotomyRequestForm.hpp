#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm;
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	const			target;
		unsigned int				timeSeed;

	public:
		RobotomyRequestForm(void);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);

		RobotomyRequestForm	&operator = (RobotomyRequestForm const &obj);

		void					execute(Bureaucrat const &bur) const;

		class FailedToRobotomizeException : public std::exception
		{
			const char		*what(void) const throw();
		};
};

#endif
