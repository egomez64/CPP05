
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	try
	{
		Intern	frank;

		frank.makeForm("TEST", "TEST");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Intern		glob;
		Bureaucrat	bob("Bob", 1);
		AForm		*form;

		form = glob.makeForm("shrubbery creation", "test");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = glob.makeForm("presidential pardon", "Fred");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = glob.makeForm("robotomy request", "Didi");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Intern glab;

		glab.makeForm("Presidential Pardon", "test");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}