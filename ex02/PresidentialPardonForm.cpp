#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm()
{
	setName("PresidentialPardonForm");
	setIsSigned();
	setToExec(5);
	setToSign(25);
	target = "Random";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm::AForm()
{
	setName("PresidentialPardonForm");
	setIsSigned();
	setToExec(5);
	setToSign(25);
	target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm::AForm(src)
{
	setName(getName(src.name));
	setIsSigned();
	setToExec(5);
	setToSign(25);
	target = _target;
}