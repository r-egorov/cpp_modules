#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Bureaucrat	thomas("Thomas", 150);
	std::cout << thomas << std::endl;

	Bureaucrat	jerry("Jerry", 10);
	std::cout << thomas << std::endl;

	ShrubberyCreationForm	shrub("home");

	/*
	 * TEST FOR NOT SIGNED FORM
	*/

	thomas.executeForm(shrub);

	/*
	 * TEST FOR TOO LOW GRADE TO EXECUTE
	*/
	jerry.signForm(shrub);

	thomas.executeForm(shrub);

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
