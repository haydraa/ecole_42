#ifndef PRESIDENTIALPARDONFOR_HPP
#define PRESIDENTIALPARDONFOR_HPP

#include <iostream>
#include "Form.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string Name;
	public:
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &init);
		PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &init);

		const	std::string	&GetName(void) const;
		virtual void execute(const Bureaucrat &executor)const;

};

#endif
