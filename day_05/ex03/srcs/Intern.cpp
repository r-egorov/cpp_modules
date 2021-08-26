#include "Intern.hpp"

static Form				*formNotFound(std::string const &target)
{
	(void)target;
	throw Intern::FormNotFoundException();
}

static Form				*makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form				*makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static Form				*makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static std::string		*str_copyLower(std::string const &s)
{
	std::locale		loc;
	std::string		*res = new std::string;
	char			c;

	res->reserve(s.length());
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		c = std::tolower(s[i], loc);
		*res += c;
	}
	return (res);
}

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern const &obj)
{
	(void)obj;
}

Intern		&Intern::operator = (Intern const &obj)
{
	(void)obj;
	return (*this);
}

Form		*Intern::makeForm(std::string const &formName,
				std::string const &target)
{
	typedef Form	*(*createForm)(std::string const &form);

	static std::string	names[6] =
	{
		"shrubbery creation",
		"shrubberycreation",
		"robotomy request",
		"robotomyrequest",
		"presidential pardon",
		"presidentialpardon"
	};

	static createForm		creators[6] =
	{
		&formNotFound,
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm,
		&makePresidentialPardonForm
	};	

	std::string			*nameLower;

	nameLower = str_copyLower(formName);

	int		index;
	index =
		(!nameLower->compare(names[0]) || !nameLower->compare(names[1])) * 1
		+ (!nameLower->compare(names[2]) || !nameLower->compare(names[3])) * 2
		+ (!nameLower->compare(names[4]) || !nameLower->compare(names[5])) * 3;

	delete nameLower;

	Form	*res;
	try
	{
		res = creators[index](target);
	}
	catch (FormNotFoundException &e)
	{
		std::cerr << "Intern can't create such a form" << std::endl;
		return (nullptr);
	}
	std::cout << "Intern creates " << *res << std::endl;
	return (res);
}

const char			*Intern::FormNotFoundException::what(void) const throw()
{
	return ("Form not found");
}

