#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <cstdlib>

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string Name;
	
	public:
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &init);
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &init);

		const std::string	GetName(void) const;
		virtual void	execute(const Bureaucrat &executor) const;
};

#endif 
