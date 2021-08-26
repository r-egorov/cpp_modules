#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : name(obj.getName()), grade(obj.getGrade()) {}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this == &obj)
		return (*this);
	new(this)Bureaucrat(obj.getName(), obj.getGrade());
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void				Bureaucrat::incGrade(void)
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void				Bureaucrat::decGrade(void)
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void				Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr
			<< *this
			<< " cannot sign " << form
			<< ", because the bureaucrat's grade is too low."
			<< std::endl;
			return ;
	}
	catch (Form::AlreadySignedException &e)
	{
		std::cerr
			<< *this
			<< " cannot sign " << form
			<<" , because it is already signed."
			<< std::endl;
			return ;
	}
	std::cout << *this << " signs " << form << std::endl;
}

const char			*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char			*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (o);
}
