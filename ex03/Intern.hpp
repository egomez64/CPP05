#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		AForm *makeForm(std::string _name, std::string _target);

	protected:
		class WrongNameException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
};

#endif