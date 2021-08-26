#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential Pardon Form", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj):
	Form(obj), target(obj.target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator = (PresidentialPardonForm const &obj)
{
	if (this == &obj)
		return (*this);
	new(this)PresidentialPardonForm(obj.target);
	Form::operator = (obj);
	return (*this);
}

void				PresidentialPardonForm::execute(Bureaucrat const &bur) const
{
	Form::execute(bur);
	std::cout << " * <" << target << "> has been pardoned by "
		<< "President of the Galaxy Zaphod Beeblebrox * "
		<< std::endl;
}
