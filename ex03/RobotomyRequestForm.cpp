#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), target("Random")
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm::AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm::AForm("RobotomyRequestForm", 72, 45), target(src.target)
{
	srand(time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->target = src.target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw(RobotomyRequestForm::NonSignException());
	if (executor.getGrade() > 45)
		throw(RobotomyRequestForm::GradeTooLowException());
	if (rand() % 2)
		std::cout << target << " has been succesfully robotomized." << std::endl;
	else
		std::cout << target << " hasn't been robotomized." << std::endl;
}