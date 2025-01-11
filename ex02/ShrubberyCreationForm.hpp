#ifndef SHRUBBETYCREATIONFORM_HPP
#define SHRUBBETYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		void execute(Bureaucrat const & executor) const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
};

#endif