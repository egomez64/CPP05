#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	fred("Fred", 1);
		fred.promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bob("Bob", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	globglob("GlobGlob", 150), globglob_jr(globglob);
		std::cout << globglob << std::endl;
		globglob_jr.demote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	glabglab("Glabglab", 3), glabglab_jr;
		std::cout << glabglab << std::endl;
		std::cout << glabglab_jr << std::endl;
		glabglab_jr = glabglab;
		std::cout << glabglab_jr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
