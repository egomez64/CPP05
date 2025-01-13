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

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

const int AForm::getToSign() const
{
	return (this->to_sign);
}

const int AForm::getToExec() const
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

const char *AForm::NonSignException::what() const throw()
{
	return ("The Form isn't sign yet");
}

std::ostream &operator<<(std::ostream &out, AForm &in)
{
	out << "Form's name : " << in.getName() << ", status : " << in.getIsSigned() << ", grade to sign :" << in.getToSign() << ", grade to execute : " << in.getToExec() << ".";
	return out;
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->getToSign())
		this->is_signed = true;
	else
		throw(AForm::GradeTooLowException());
}

void AForm::setName(const std::string _name)
{
	name = _name;
}

void AForm::setIsSigned()
{
	is_signed = false;
}

void AForm::setToSign(int _to_sign)
{
	to_sign = _to_sign;
}

void AForm::setToExec(int _to_exec)
{
	to_exec = _to_exec;
}