#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat	thomas("Thomas", 150);
	std::cout << thomas << std::endl;

	Bureaucrat	jerry("Jerry", 10);
	std::cout << jerry << std::endl;

	Bureaucrat	superior("Superior", 1);
	std::cout << jerry << std::endl;

	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		rob("Pinocchio");
	PresidentialPardonForm	pres("Arthur Dent");

	/*
	 * TEST FOR NOT SIGNED FORM
	*/

	thomas.signForm(rob);
	thomas.signForm(pres);
	thomas.executeForm(shrub);
	thomas.executeForm(pres);

	/*
	 * TEST FOR TOO LOW GRADE TO EXECUTE
	*/
	jerry.signForm(shrub);
	jerry.signForm(rob);
	jerry.signForm(pres);

	thomas.executeForm(shrub);
	thomas.executeForm(rob);

	jerry.executeForm(rob);
	superior.executeForm(pres);

	/*
	 * TEST FOR MANAGING FILES' ERRORS
	*/
	try
	{
		thomas.executeForm(shrub);
		jerry.executeForm(shrub);
	}
	catch (ShrubberyCreationForm::FailedToOpenException &e)
	{
		std::cerr << "Can't open the file for Shrubbery Creation Form!" << std::endl;
	}
	catch (ShrubberyCreationForm::FailedToWriteException &e)
	{
		std::cerr << "Can't write to the file for Shrubbery Creation Form!" << std::endl;
	}
	return (0);
}
