#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name):
	AForm("ShrubberyCreationForm", 145, 137), Name(name)
{
//	std::cout << "Constructor Called For Shrubbery" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void): 
	AForm("ShrubberyCreationForm", 145, 137) ,Name("")
{
//	std::cout << "Constructor For Default Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &init):
	AForm("ShrubberyCreationForm", 145, 137), Name(init.GetName())
{
	if (this != &init)
		*this = init;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
//	std::cout << "Destructor Called For Shrubbery" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &init)
{
//	std::cout << "Assignment Operator Called" << std::endl;
//	std::cout << "cant copy the Name it is const" << std::endl;
	(void)init;
	return (*this);
}

const std::string ShrubberyCreationForm::GetName(void) const
{
	return (Name);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string Filename = this->Name + "_shrubbery";
	std::ofstream outfile;
	
	this->checkExecutability(executor);
	outfile.open(Filename.c_str(), std::ios::out);
	//protect out file;
	outfile << "		  * " << std::endl;
    outfile << "		 /|\\" << std::endl;
    outfile << "		/*|O\\" << std::endl;
    outfile << "       /*/|\\*\\" << std::endl;
    outfile << "      /X/O|*\\X\\" << std::endl; 
    outfile << "     /*/X/|\\X\\*\\" << std::endl;
    outfile << "    /O/*/X|*\\O\\X\\" << std::endl;
    outfile << "   /*/O/X/|\\X\\O\\*\\" << std::endl;
    outfile << "  /X/O/*/X|O\\X\\*\\O\\" << std::endl;
    outfile << " /O/X/*/O/|\\X\\*\\O\\X\\" << std::endl;
    outfile << "         |X|      " << std::endl;
    outfile << "         |X|  " << std::endl;
	std::cout << "Created The Shrug in " << this->Name << "_shrubbery" << std::endl;
}

