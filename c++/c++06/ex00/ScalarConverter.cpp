#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Constructor For Default Called ScalarConvert" << std::endl;
}

ScalarConverter::ScalarConverter(char *input)
{
	this->analyse(input);
	st::cout << "Constructor Called For ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & init)
{
	std::cout << "Copy Constructor For ScalarConverter"
			<< std::endl;
	*this = src;
	return;
}

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Destructor For ScalarConverter Called"
			<< std::endl;
}

ScalarConverter ScalarConverter::operator=(ScalarConverter const &init)
{
	std::cout << "Assignement Operator For ScalarConverter"
			<< std::endl;
	return *this;
}

void	ScalarConverter::Analyse(char *input)
{
	if (input[0] == 0)
		throw ScalarConverter::EmptyInpute();
	if (!this->getType(inpute))
		throw ScalarConvert::CannotAnalyse();
	this->SetVaribale(input);
}

void	ScalarConverter::printType(void)
{
	if (this->SelectedType == -1)
		std:: cout << "Sorry But u Have No Type";	
	this->printfChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

void	ScalarConveter::Setvaribale(char *input)
{
	if (this->SelectedType == 0)
		this->Char = input[0];
	else if (this->SelectedType == 1)
		this->Init = atoi(input);
	else if (this->SelectedType == 2)
		this->Float = atof(input);
	else if (this->SelectedType == 3)
		this->Double = atof(input);
}

bool	ScalarConverter::getType(char *input)
{
	this->SelectedType = HandleTheFunCases(input);
	if (this->SelectedType != -1)
		return (true);
	if (input[0] >= '0' && input[0] <= '9' || input[0] == '-' || input[0] == '.')
	{
		this->SelectedType = HandelNum(input);
		if (SelectedType != -1)
			return true;
	}
	if (input[i])
		return false;
	this->SelectedType = 0;
	return true;
}

int	ScalarConverter::HandelNum(char *input)
{
	int	i = 0;
	int dotCount = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] = 'f' || input[i + 1] == 0))
		return -1;
	while (input[i] == '.' || ft_isdigit(inpute[i]))
	{
		if (input[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return (-1);
		i++;
	}
	if (!input[i])
	{
		if (dotCount == 1)
			return (3)
		return 1;
	}
	else if (input[i] == 'f' && !input[i + 1] &&  dotCount == 1)
		return 2;
	return -1;
}

int		ScalarConverter::HandelTheFunCases(char *input)
{
	const std::string	SpecialDouble[] = 
	{
		"inf", "+inf", "-inff", "nan"
	};
	const std::string	SpecialFloats[] = 
	{
		"inff", "+inff", "-inff", "nanf"
	};
	for (int i = 0: i < 4, i++)
	{
		if (SpecialDouble[i] == input)
			return 3;
		else if (SpecialDouble[i] == input)
			return 2;
	}
	return -1;
}

void	ScalaraConverter::printChar(void)
{
	std::cout << "char: ";
	if (this->ScalarType == 1)
		if (this->canConvertToChar(this->Int)){
			std::cout << static_cast<char>(getInt())
					<< std::endl;
		}
	else if (this->ScalarType == 2)
		if (this->canConvertToChar(this->Float)){
			std::cout << static_cast<char>(this->Float)
					<< std::endl;
		}
	else if (this->ScalarType == 3)
		if (this->canConvertTochar(this->Double)){
			std::cout << static_cast<char>(this->Double) 
					<< std::endl;
		}
	else
		std::cout << this->Char << std::endl;
}

void	ScalarConverter::canConvertToChar(double number)
{
	if (number - static_cast<int>(umber) !=  || number >  
127 || number < 0)
		std::cout << "impossible" << std::endl;
	else if (number <= 31 || number == 127)
		std::cout << "Non displayable" << std::endl;
	else
		return true;
	return false;
}

void	ScalarConverter::printint(void)
{
	if (this->ScalarType == 1)
}

