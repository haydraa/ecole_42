#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string Name;
		bool	Signed;
		const int GradeToSigned;
		const int GradeToExecute;
	
	public :
		Form(void);
		Form(const std::string Name, int Gts, int Gte);
		Form(const Form &init);
		~Form(void);
		
		Form &operator=(const Form &init);

		const	std::string &GetName(void) const;
		bool	getSigned();
		int		getGradeToSigned() const;
		int		getGradeToExecute() const;
		bool	beSigned(const Bureaucrat& bureau);
		void	checkExecutability(const Bureaucrat& bureau) const;
		
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char * what() const throw()
				{
					return ("Grade To High");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw();
		};

		class CantExecuteForm : public std::exception
		{
			public :
				const char * what() const throw();
		};
};

std::ostream &operator<<(std:: ostream &ostr, Form &init);

#endif
