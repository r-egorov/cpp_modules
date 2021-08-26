#include "RobotomyRequestForm.hpp"

static unsigned int	getTimeSeed(void)
{
	unsigned int	seed;

	seed = time(0);
	srand(seed);
	return (seed);
}

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Robotomy Request Form", 72, 45), target("default"), timeSeed(getTimeSeed())
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Robotomy Request Form", 72, 45), target(target), timeSeed(getTimeSeed())
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj):
	Form(obj), target(obj.target) {}

RobotomyRequestForm	&RobotomyRequestForm::operator = (RobotomyRequestForm const &obj)
{
	if (this == &obj)
		return (*this);
	new(this)RobotomyRequestForm(obj.target);
	Form::operator = (obj);
	return (*this);
}

void				RobotomyRequestForm::execute(Bureaucrat const &bur) const
{
	Form::execute(bur);
	std::cout << " * BEEP BOP BOOP * \n * BZZZZZZZZZZZZ DDDDRRRRRRRRRRRRR * "
		<< std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << " * <" << target << "> was successfully robotomized * "
			<< std::endl;
	}
	else
	{
		std::cerr << " * <" << target << "> failed to be robotomized * "
			<< std::endl;
	}
}
