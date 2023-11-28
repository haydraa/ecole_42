#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_Name("")
{
	std::cout << "Constrictor For Default Called" << std::endl;
	_Grade = LowGrade;
}

Bureaucrat::Bureaucrat(const std::string Name, int grade): _Name(Name), _Grade(grade)
{
	std::cout << "Constructor For Bureaucrat Called" << std::endl;
	if (_Grade < Bureaucrat::HightGrade)
		throw Bureaucrat::GradeTooHightException();
	else if (_Grade > Bureaucrat::LowGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &src)
		*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor For Bureaucrat Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &init)
{
	std::cout << "Assignment operator for bureaucrat" << std::endl;
	if (this != &init)
		_Grade = init.GetGrade();
	std::cout << "Can't copy the name (it's const)" << std::endl;
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too hight");
}

const char* Bureaucrat::GradeTooHightException::what() const throw()
{
	return ("The grade you set is too hight");
}

bool	Bureaucrat::signForm(Form &form)
{
	if (form.beSigned(*this))
	{
		std::cout << this->_Name << " Signs Form" << form.GetName() << std::endl;
		return (true);
	}
	else
		std::cout << this->_Name << " Cannot Sign Form " << form.GetName()
		<< " because their Grade Is Not High Enough " << std::endl;
	return (false);
}

bool	Bureaucrat::executeForm(const Form &Form) const
{
	try
	{
		Form.checkExecutability(*this);
		std::cout << this->_Name << " Execute Form " << Form.GetName() << std::endl;
		return (true);
	}
	catch (Form::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

const std::string	&Bureaucrat::GetName(void)const
{
	return this->_Name;
}

int	Bureaucrat::GetGrade(void) const
{
	return this->_Grade;
}

void	Bureaucrat::IncrementGrade(int up)
{
	_Grade -= up;
	if (_Grade < Bureaucrat::HightGrade)
		throw Bureaucrat::GradeTooHightException();
	else if (_Grade > Bureaucrat::LowGrade)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::DecrementGrade(int down)
{
	_Grade += down;
	if (_Grade < Bureaucrat::HightGrade)
		throw Bureaucrat::GradeTooHightException();
	else if (_Grade > Bureaucrat::LowGrade)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & ostr, Bureaucrat  &init)
{
	ostr << init.GetName() << ", Bureaucrat Grade " << 
		init.GetGrade();
	return ostr;
}


