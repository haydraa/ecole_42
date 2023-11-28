#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

// SGrade to signed;
// Egrade to execute;

class AForm
{
	private :
		const std::string Name;
		bool	Signed;
		const int SGrade;
		const int EGrade;
	
	public :
		AForm(void);
		AForm(const std::string Name, int Gts, int Gte);
		AForm(const AForm &init);
		virtual ~AForm(void);
		
		AForm &operator=(const AForm &init);

		const	std::string &GetName(void) const;
		bool	getSigned();
		int		getGradeToSigned() const;
		int		getGradeToExecute() const;
		bool	beSigned(const Bureaucrat& bureau);
		void	checkExecutability(const Bureaucrat& bureau) const;
		virtual void execute(const Bureaucrat &executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw();
			
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

std::ostream &operator<<(std:: ostream &ostr, AForm &init);

#endif
