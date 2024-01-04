#include "Form.hpp"

AForm::AForm(void) : Name(""), Signed(false), SGrade(0), EGrade(0)
{
//	std::cout << "Constructor For Default Form Called" << std::endl;
}

AForm::AForm(const std::string Name, int Gts, int Gte)
:Name(Name), Signed(false), SGrade(Gts), EGrade(Gte)
{
//	std::cout << "Constructor Form Called" << std::endl;
	if (SGrade < 1 || EGrade < 1)
		throw AForm::GradeTooHighException();
	else if(SGrade > 150 || EGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &init): 
		SGrade(init.getGradeToSigned()), EGrade(init.getGradeToExecute())
{
	if (this != &init)
		*this = init;
	return;
}

AForm &AForm::operator=(const AForm &init)
{
//	std::cout << "Assignment operator For Form Called" << std::endl;
	if (this != &init)
	{
		Signed = getSigned();		
//		std::cout << "Can't copy the name or mrade e and garde s(it's const)" << std::endl;
	}
	return (*this);
}

AForm::~AForm(void)
{
//	std::cout << "Destructor Called for Form" << std::endl;
}

const std::string &AForm::GetName(void) const
{
	return (Name);
}

bool	AForm::getSigned(void)
{
	return (Signed);
}

int	AForm::getGradeToSigned()const
{
	return (SGrade);
}

int	AForm::getGradeToExecute()const
{
	return (EGrade);
}

void	AForm::checkExecutability(const Bureaucrat &bureau)const
{
	if (Signed == false || bureau.GetGrade() > EGrade)
			throw AForm::CantExecuteForm();
}

bool	AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.GetGrade() < this->SGrade)
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

std::ostream &operator<<(std::ostream &ostr, AForm &init)
{
	ostr <<  "Form " << init.GetName() 
		<< " Need: " << init.getGradeToSigned() 
		<< " garde to Be Signed" << std::endl
		<< "and: " << init.getGradeToExecute() 
		<< " garde To be Executed" << std::endl 
		<< ((init.getSigned()) ? "" : "Not ") << "Signed";
	return (ostr);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade To High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade To Low");
}

const char* AForm::CantExecuteForm::what() const throw()
{
	return ("Can't execut Form");
}
