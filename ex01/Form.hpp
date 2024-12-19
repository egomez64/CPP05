#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int to_sign;
		const int to_exec;

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
		Form();
		Form(const std::string _name, const int _to_sign, const int _to_exec);
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &src);

	public:
		const std::string getName();
		bool getIsSigned();
		const int getToSigned();
		const int getToExec();
		void beSigned(Bureaucrat &bur);
};

std::ostream &operator<<(std::ostream &out, Form &in);

#endif