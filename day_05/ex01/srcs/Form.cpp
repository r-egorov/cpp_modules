#include "Form.hpp"

int					validateGrade(int grade)
{
	if (grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Form::GradeTooLowException();
	}
	return (grade);
}

Form::Form(void) : isSigned(false), signGrade(0), execGrade(0) {}

Form::~Form(void) {}

Form::Form(std::string name, int const signGrade, int const execGrade) :
	name(name),
	isSigned(false),
	signGrade(validateGrade(signGrade)),
	execGrade(validateGrade(execGrade))
{
	/*
	if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooLowException();
	}
	this->signGrade = signGrade;
	this->execGrade = execGrade;
	*/
}

Form::Form(Form const &obj) :	name(obj.getName()),
								isSigned(obj.wasSigned()),
								signGrade(obj.getSignGrade()),
								execGrade(obj.getExecGrade())
{}

Form				&Form::operator = (Form const &obj)
{
	if (this == &obj)
		return (*this);
	new(this)Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade());
	this->isSigned = obj.wasSigned();
	return (*this);
}

std::string const	&Form::getName(void) const
{
	return (this->name);
}

int					Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int					Form::getExecGrade(void) const
{
	return (this->execGrade);
}

bool				Form::wasSigned(void) const
{
	return (this->isSigned);
}

void				Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->signGrade)
	{
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

const char			*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char			*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream		&operator << (std::ostream &o, Form const &obj)
{
	o 
		<< "Form " << obj.getName()
		<< ", grade to sign: " << obj.getSignGrade()
		<< ", grade to exectute: " << obj.getExecGrade()
		<< ", signature status: " << obj.wasSigned();
	return (o);
}