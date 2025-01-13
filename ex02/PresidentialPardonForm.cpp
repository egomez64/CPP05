#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresdentialPardonForm", 25, 5), target("Random")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm::AForm("PresdentialPardonForm", 25, 5), target(_target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm::AForm("PresdentialPardonForm", 25, 5), target(src.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->target = src.target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw(PresidentialPardonForm::NonSignException());
	if (executor.getGrade() > 5)
		throw(PresidentialPardonForm::GradeTooLowException());
	std::cout << target << " has been pardon by Zaphod Beeblebrox." << std::endl;
}