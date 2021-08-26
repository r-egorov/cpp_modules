#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	thomas("Thomas", 10);
	std::cout << thomas << std::endl;

	Bureaucrat	andrew("Andrew", 140);
	std::cout << andrew << std::endl;

	Bureaucrat	kathy("Kathy", 20);
	std::cout << kathy << std::endl;

	/*
	 * TESTING TOO LOW EXCEPTION FOR A BUREAUCRAT
	*/
	try
	{

		for (int i = 0; i < 20; i++)
		{
			andrew.decGrade();
			std::cout << "Decrementing Andrew's grade by 1" << std::endl;
			std::cout << andrew << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade is too low!" << std::endl << std::endl;
	}

	/*
	 * TESTING TOO HIGH EXCEPTION FOR A BUREAUCRAT
	*/
	try
	{
		for (int i = 0; i < 20; i++)
		{
			thomas.incGrade();
			std::cout << "Incrementing Thomas's grade by 1" << std::endl;
			std::cout << thomas << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade is too high!" << std::endl << std::endl;
	}

	/*
	 * TESTING FORM'S EXCEPTION
	*/

	Form		b28("b28", 19, 40);

	/*
	 * TESTING FORM'S TOO LOW GRADE TO SIGN EXCEPTION
	*/

	kathy.signForm(b28);
	std::cout << b28 << std::endl;

	thomas.signForm(b28);
	std::cout << b28 << std::endl;

	std::cout << "TRYING TO SIGN ALREADY SIGNED FORM" << std::endl;
	thomas.signForm(b28);
	std::cout << b28 << std::endl;
	return (0);
}
