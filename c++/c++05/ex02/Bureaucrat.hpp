#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _Name;
		int _Grade;
		static const int LowGrade = 150;
		static const int HightGrade = 1;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string Name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &init);

		const std::string	&GetName(void) const;
		int		GetGrade(void) const;
		void	IncrementGrade(int up);
		void	DecrementGrade(int Down);

		bool	signForm(AForm &form);
		bool    executeForm(const AForm &Form) const;

		class GradeTooHightException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &ostr, Bureaucrat &init);

#endif 
