#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name)
{
	if (_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName()), grade(src.getGrade())
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->grade = src.getGrade();
		const_cast<std::string &>(this->name) = src.getName();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::promote()
{
	if (this->grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade--;
}

void Bureaucrat::demote()
{
	if (this->grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Bureaucrat's grade was set too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Bureaucrat's grade was set too low");
}
