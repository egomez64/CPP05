#include "Form.hpp"

Form::Form() : name("Basic"), is_signed(false), to_sign(150), to_exec(150)
{}

Form::Form(const std::string _name, const int _to_sign, const int _to_exec) : name(_name), is_signed(false), to_sign(_to_sign), to_exec(_to_exec)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw (Form::GradeTooLowException());
	else if (_to_sign < 1 || _to_exec < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form &src) : name(src.name), to_sign(src.to_sign), to_exec(src.to_exec), is_signed(src.is_signed)
{}

Form &Form::operator=(const Form &src)
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

Form::~Form()
{}

const std::string Form::getName()
{
	return (this->name);
}

bool Form::getIsSigned()
{
	return (this->is_signed);
}

const int Form::getToSigned()
{
	return (this->to_sign);
}

const int Form::getToExec()
{
	return (this->to_exec);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The Form's grade was set too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The Form's grade was set too low");
}

std::ostream &operator<<(std::ostream &out, Form &in)
{
	out << "Form's name : " << in.getName() << ", status : " << in.getIsSigned() << ", grade to sign :" << in.getToSigned() << ", grade to execute : " << in.getToExec() << ".";
	return out;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->getToSigned())
		this->is_signed = true;
	else
		throw(Form::GradeTooLowException());
}
