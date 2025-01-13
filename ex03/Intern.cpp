#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

AForm *Intern::makeForm(std::string _name, std::string _target)
{
	int which;
	std::string nameForm[4] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	for (which = 0; which < 4; which++)
	{
		if (_name == nameForm[which])
			break;
	}
	switch (which)
	{
		case 0:
			return (new ShrubberyCreationForm(_target));
		case 1:
			return (new PresidentialPardonForm(_target));
		case 2:
			return (new RobotomyRequestForm(_target));
		default:
			throw(Intern::WrongNameException());
	}
}

const char *Intern::WrongNameException::what() const throw()
{
	return "There is no form with this name.";
}