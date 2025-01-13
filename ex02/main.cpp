
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		ShrubberyCreationForm	form1("Garden");
		PresidentialPardonForm	form2("Bob");
		RobotomyRequestForm		form3("Bender");
		Bureaucrat				bob("Bob", 1);

		bob.signForm(form1);
		bob.signForm(form2);
		bob.signForm(form3);
		bob.executeForm(form1);
		bob.executeForm(form2);
		bob.executeForm(form3);
	}
	{
		ShrubberyCreationForm	form("Backyard");
		Bureaucrat				fred("Fred", 1), globox("Globox", 150);

		fred.executeForm(form);
		fred.signForm(form);
		globox.executeForm(form);
		std::cout << form << std::endl;
	}
	try
	{
		RobotomyRequestForm	form("Baba");
		Bureaucrat			globglob("Globglob", 1);
		Bureaucrat			glabglab("Glabglab", 150);
		
		form.beSigned(globglob);
		form.execute(glabglab);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
