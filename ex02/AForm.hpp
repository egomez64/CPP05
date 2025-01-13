#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string name;
		bool is_signed;
		int to_sign;
		int to_exec;

	public:
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
		class NonSignException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:
		AForm();
		AForm(const std::string _name, const int _to_sign, const int _to_exec);
		virtual ~AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);

	public:
		const std::string getName() const;
		bool getIsSigned() const;
		const int getToSign() const;
		const int getToExec() const;
		void setName(const std::string _name);
		void setIsSigned();
		void setToSign(const int _to_sign);
		void setToExec(const int _to_exec);
		void beSigned(Bureaucrat &bur);
		virtual void execute(Bureaucrat const & executor) const= 0;
};

std::ostream &operator<<(std::ostream &out, AForm &in);

#endif