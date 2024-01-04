#include "Form.hpp"

Form::Form(void) : Name(""), Signed(false), GradeToSigned(0), GradeToExecute(0)
{
	std::cout << "Constructor For Default Form Called" << std::endl;
}

Form::Form(const std::string Name, int Gts, int Gte)
:Name(Name), Signed(false), GradeToSigned(Gts), GradeToExecute(Gte)
{
	std::cout << "Constructor Form Called" << std::endl;
	if (GradeToSigned < 1 || GradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if(GradeToSigned > 150 || GradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &init): 
		GradeToSigned(init.getGradeToSigned()), GradeToExecute(init.getGradeToExecute())
{
	if (this != &init)
		*this = init;
	return;
}

Form &Form::operator=(const Form &init)
{
	std::cout << "Assignment operator For Form Called" << std::endl;
	if (this != &init)
	{
		Signed = getSigned();		
		std::cout << "Can't copy the name or grade e and garde s(it's const)" << std::endl;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade To Hight");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade To Low");
}

const char* Form::CantExecuteForm::what() const throw()
{
	return ("Grade To Low");
}
	
Form::~Form(void)
{
	std::cout << "Destructor Called for Form" << std::endl;
}

const std::string &Form::GetName(void) const
{
	return (Name);
}

bool	Form::getSigned(void)
{
	return (Signed);
}

int	Form::getGradeToSigned()const
{
	return (GradeToSigned);
}

int	Form::getGradeToExecute()const
{
	return (GradeToExecute);
}

void	Form::checkExecutability(const Bureaucrat &bureau)const
{
	if (Signed == false || bureau.GetGrade() < GradeToExecute)
			throw Form::CantExecuteForm();
}

bool	Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.GetGrade() < this->GradeToSigned)
	{
		Signed = true;
		return (true);
	}
	else
	{
		Signed = false;
		return (false);
	}
}

std::ostream &operator<<(std::ostream &ostr, Form &init)
{
	ostr <<  "Form " << init.GetName() 
		<< " Need: " << init.getGradeToSigned() 
		<< " garde to Be Signed" << std::endl
		<< "and: " << init.getGradeToExecute() 
		<< " garde To be Executed" << std::endl 
		<< ((init.getSigned()) ? "" : "Not ") << "Signed";
	return (ostr);
}

