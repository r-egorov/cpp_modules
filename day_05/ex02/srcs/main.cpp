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

	try
	{
		shrub.execute(thomas);
	}
	catch (Form::NotSignedException &e)
	{
		std::cerr
			<< thomas << " can't execute " << shrub 
			<< ", the form is not signed!" << std::endl;
	}

	/*
	 * TEST FOR TOO LOW GRADE TO EXECUTE
	*/
	jerry.signForm(shrub);

	try
	{
		shrub.execute(thomas);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr
			<< thomas << " can't execute " << shrub 
			<< ", grade is too low!" << std::endl;
	}

	/*
	 * TEST FOR MANAGING FILES' ERRORS
	*/
	try
	{
		shrub.execute(jerry);
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
