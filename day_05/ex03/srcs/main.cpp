#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Intern	intern;
	Form	*someForm;
	Form	*p_shrub;
	Form	*p_rob;
	Form	*p_pres;

	p_rob = intern.makeForm("Robotomy Request", "Bender");
	p_pres = intern.makeForm("pResIdeNtiaLpardon", "Arthur Dent");
	p_shrub = intern.makeForm("shrubbery cReAtion", "home");
	someForm = intern.makeForm("some form", "Bender");

	Bureaucrat	thomas("Thomas", 150);
	std::cout << thomas << std::endl;

	Bureaucrat	jerry("Jerry", 10);
	std::cout << jerry << std::endl;

	Bureaucrat	superior("Superior", 1);
	std::cout << jerry << std::endl;

	/*
	 * TEST FOR NOT SIGNED FORM
	*/

	thomas.signForm(*p_rob);
	thomas.signForm(*p_pres);
	thomas.executeForm(*p_shrub);
	thomas.executeForm(*p_pres);

	/*
	 * TEST FOR TOO LOW GRADE TO EXECUTE
	*/
	jerry.signForm(*p_shrub);
	jerry.signForm(*p_rob);
	jerry.signForm(*p_pres);

	thomas.executeForm(*p_shrub);
	thomas.executeForm(*p_rob);

	jerry.executeForm(*p_rob);
	superior.executeForm(*p_pres);

	/*
	 * TEST FOR MANAGING FILES' ERRORS
	*/
	try
	{
		thomas.executeForm(*p_shrub);
		jerry.executeForm(*p_shrub);
	}
	catch (ShrubberyCreationForm::FailedToOpenException &e)
	{
		std::cerr << "Can't open the file for Shrubbery Creation Form!" << std::endl;
	}
	catch (ShrubberyCreationForm::FailedToWriteException &e)
	{
		std::cerr << "Can't write to the file for Shrubbery Creation Form!" << std::endl;
	}
	delete p_rob;
	delete p_pres;
	delete p_shrub;

	return (0);
}
