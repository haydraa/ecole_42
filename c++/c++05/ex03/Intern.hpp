#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
	private:
		typedef struct s_form
		{
			std::string formName;
			AForm *type;
		}	t_form;

	public:
		Intern(void);
		Intern(const Intern &init);
		~Intern(void);

		Intern &operator=(const Intern &init);

		AForm 	*makeForm(std::string Form, std::string Object)const ;

};


#endif
