#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
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
		AForm();
		AForm(const std::string _name, const int _to_sign, const int _to_exec);
		~AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);

	public:
		const std::string getName();
		bool getIsSigned();
		const int getToSigned();
		const int getToExec();
		void beSigned(Bureaucrat &bur);
		virtual void execute(Bureaucrat const & executor) const= 0;
};

std::ostream &operator<<(std::ostream &out, AForm &in);

#endif