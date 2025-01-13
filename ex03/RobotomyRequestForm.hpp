#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include<cstdlib>
#include<ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		void execute(Bureaucrat const & executor) const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};

#endif