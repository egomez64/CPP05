
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	fred("Fred", 1), bob("Bob", 150);
		Form		form1("Form 1", 1, 1), form2(form1), form3;

		form3 = form1;
		std::cout << form1 << std::endl;
		std::cout << form3 << std::endl;
		form1.beSigned(fred);
		std::cout << form1 << std::endl;
		std::cout << form3 << std::endl;
		fred.signForm(form2);
		form1.beSigned(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	bob("Bob", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	globglob("GlobGlob", 151, 151);
		std::cout << globglob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	glabglab("Glabglab", 100);
		Form		glabform("Glab Form", 1, 1);

		std::cout << glabglab << std::endl;
		std::cout << glabform << std::endl;
		glabglab.signForm(glabform);
		glabform.beSigned(glabglab);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
