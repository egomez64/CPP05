#include "AForm.hpp"

AForm::AForm() : name("Basic"), is_signed(false), to_sign(150), to_exec(150)
{}

AForm::AForm(const std::string _name, const int _to_sign, const int _to_exec) : name(_name), is_signed(false), to_sign(_to_sign), to_exec(_to_exec)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw (AForm::GradeTooLowException());
	else if (_to_sign < 1 || _to_exec < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm &src) : name(src.name), to_sign(src.to_sign), to_exec(src.to_exec), is_signed(src.is_signed)
{}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		const_cast<std::string &>(this->name) = src.name;
		const_cast<int &>(this->to_sign) = src.to_sign;
		const_cast<int &>(this->to_exec) = src.to_exec;
		this->is_signed = src.is_signed;
	}
	return (*this);
}

AForm::~AForm()
{}

const std::string AForm::getName()
{
	return (this->name);
}

bool AForm::getIsSigned()
{
	return (this->is_signed);
}

const int AForm::getToSigned()
{
	return (this->to_sign);
}

const int AForm::getToExec()
{
	return (this->to_exec);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The Form's grade was set too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The Form's grade was set too low");
}

std::ostream &operator<<(std::ostream &out, AForm &in)
{
	out << "Form's name : " << in.getName() << ", status : " << in.getIsSigned() << ", grade to sign :" << in.getToSigned() << ", grade to execute : " << in.getToExec() << ".";
	return out;
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->getToSigned())
		this->is_signed = true;
	else
		throw(AForm::GradeTooLowException());
}
