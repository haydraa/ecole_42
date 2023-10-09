#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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

		bool	signForm(Form &form);
		bool    executeForm(const Form &Form) const;

		class GradeTooHightException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The grade you set is too hight");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The grade you set is too low");
				}
		};
};

std::ostream &operator<<(std::ostream &ostr, Bureaucrat &init);

#endif 
