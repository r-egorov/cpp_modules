#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	bur("Thomas", 10);
	std::cout << bur << std::endl;

	Bureaucrat	bur1("Andrew", 140);
	std::cout << bur1 << std::endl;

	Bureaucrat	bur2("Kathy", 20);
	bur2 = bur;
	std::cout << bur2 << std::endl;

	/*
	 * TESTING TOO LOW EXCEPTION FOR A BUREAUCRAT
	*/
	try
	{

		for (int i = 0; i < 20; i++)
		{
			bur1.decGrade();
			std::cout << "Decrementing Andrew's grade by 1" << std::endl;
			std::cout << bur1 << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade is too low!" << std::endl;
	}

	/*
	 * TESTING TOO HIGH EXCEPTION FOR A BUREAUCRAT
	*/
	try
	{
		for (int i = 0; i < 20; i++)
		{
			bur.incGrade();
			std::cout << "Incrementing Thomas's grade by 1" << std::endl;
			std::cout << bur << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade is too high!" << std::endl;
	}
	return (0);
}
