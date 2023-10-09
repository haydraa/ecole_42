#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class 	ShrubberyCreationForm : public AForm
{
	private:
		const std::string Name;
	
	public:	
		ShrubberyCreationForm(const std::string &name);
		ShrubberyCreationForm(const ShrubberyCreationForm &init);
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &init);
	
		virtual	void	execute(const Bureaucrat &executor)const;	
		const std::string GetName(void) const;
};

#endif
