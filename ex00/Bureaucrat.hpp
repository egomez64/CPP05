#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	private:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:
		const std::string getName() const;
		int getGrade() const;
		void promote();
		void demote();

	public:
		Bureaucrat();
		Bureaucrat(const std::string _name, int _grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &in);

#endif