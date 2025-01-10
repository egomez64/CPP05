#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		void execute(Bureaucrat const & executor) const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string _name, const int _to_sign, const int _to_exec);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};

#endif