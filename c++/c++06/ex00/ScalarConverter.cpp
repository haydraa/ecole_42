#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &init)
{
	std::cout << "Copy Constructor For ScalarConverter"
			<< std::endl;
	if (this != &init)
		*this = init;
	return;
}

ScalarConverter::ScalarConverter(char *input):
ScalarType(-3), Float(0), Double(0), Int(0), Char('\0')
{
	this->Analyse(input);
	std::cout << "Constructor Called For ScalarConverter" 
		<< std::endl;
}

ScalarConverter::ScalarConverter(void):
ScalarType(-3), Float(0), Double(0), Int(0), Char('\0')
{
	std::cout << "Constructor For Default Called ScalarConvert" << std::endl;
}



ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor For ScalarConverter Called"
			<< std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &init)
{
	this->ScalarType = init.ScalarType;
	this->Int = init.Int;
	this->Float = init.Float;
	this->Char = init.Char;
	this->Double = init.Double;
	std::cout << "Assignement Operator For ScalarConverter"
			<< std::endl;
	return *this;
}

void	ScalarConverter::Analyse(char *input)
{
	if (input[0] == 0)
		throw ScalarConverter::EmptyInput();
	if (!this->getType(input))
		throw ScalarConverter::CannotAnalyse();
	this->SetVaribale(input);
}

void	ScalarConverter::printType(void)
{
	if (this->ScalarType == -1)
		std:: cout << "Sorry But u Have No Type";	
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

void	ScalarConverter::SetVaribale(char *input)
{
	if (this->ScalarType == 0)
		this->Char = input[0];
	else if (this->ScalarType == 1)
		this->Int = atoi(input);
	else if (this->ScalarType == 2)
		this->Float = atof(input);
	else if (this->ScalarType == 3)
		this->Double = atof(input);
}

bool	ScalarConverter::getType(char *input)
{
	this->ScalarType = HandelTheFunCases(input);
	if (this->ScalarType != -1)
		return (true);
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-' || input[0] == '.')
	{
		this->ScalarType = HandelNum(input);
		if (ScalarType != -1)
			return true;
	}
	if (input[0])
		return false;
	this->ScalarType = 0;
	return true;
}

bool ScalarConverter::ft_isdigits(char c)
{
	return (c >= '0' && c <= '9');
}

int	ScalarConverter::HandelNum(char *input)
{
	int	i = 0;
	int dotCount = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] = 'f' || input[i + 1] == 0))
		return -1;
	while (input[i] == '.' || ft_isdigits(input[i]))
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
			return (3);
		return (1);
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
	for (int i = 0; i < 4; i++)
	{
		if (SpecialDouble[i] == input)
			return 3;
		else if (SpecialFloats[i] == input)
			return 2;
	}
	return -1;
}

void	ScalarConverter::printChar(void)
{
	std::cout << "char: ";
	if (this->ScalarType == 1){
		if (this->canConvertToChar(this->Int)){
			std::cout << static_cast<char>(this->Int)
					<< std::endl;
		}
	}
	else if (this->ScalarType == 2){
		if (this->canConvertToChar(this->Float)){
			std::cout << static_cast<char>(this->Float)
					<< std::endl;
		}
	}
	else if (this->ScalarType == 3){
		if (this->canConvertToChar(this->Double)){
			std::cout << static_cast<char>(this->Double) 
					<< std::endl;
		}
	}
	else
		std::cout << this->Char << std::endl;
}

bool ScalarConverter::canConvertToInt(double Number)
{
	return (Number <= std::numeric_limits<int>::max()
		&& Number >= std::numeric_limits<int>::min()
		&& Number != std::numeric_limits<double>::infinity()
		&& Number != std::numeric_limits<double>::infinity()
		&& Number != std::numeric_limits<double>::quiet_NaN());
}

bool ScalarConverter::canConvertToFloat(double Number)
{
	return ((Number <= std::numeric_limits<float>::max() 
		&& Number >= -std::numeric_limits<double>::max())
		|| Number == std::numeric_limits<double>::infinity()
		|| Number == -std::numeric_limits<double>::infinity()
		|| Number == -std::numeric_limits<double>::infinity()
		|| std::isnan(Number));
}

bool	ScalarConverter::canConvertToChar(double Number)
{
	if (Number - static_cast<int>(Number) != 0 || Number >  
127 || Number < 0)
		std::cout << "impossible" << std::endl;
	else if (Number <= 31 || Number == 127)
		std::cout << "Non displayable" << std::endl;
	else
		return true;
	return false;	
}

const char	*ScalarConverter::printDotZero(double Number)
{
	if (Number - static_cast<int>(Number) == 0.0)
			return (".0");
	return ("");
}

void	ScalarConverter::printInt(void)
{
	std::cout << "int: ";
	if (this->ScalarType == 0){
		std::cout << static_cast<int>(this->Char)
				<< std::endl;
	}
	else if (this->ScalarType == 1)
		std::cout << this->Int << std::endl;
	else if (this->ScalarType == 2)
	{
		if (canConvertToInt(this->Float))
			std::cout << static_cast<int>(this->Float) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	else if (this->ScalarType == 3)
	{
		if (canConvertToInt(this->Double))
			std::cout << static_cast<int>(this->Double) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::printFloat(void)
{
	std::cout << "float: ";
	if (this->ScalarType == 0)
		std::cout << static_cast<float>(this->Char) << .0f
				<< std::endl;
	else if (this->ScalarType == 1)
		std::cout << static_cast<float>(this->Int) << ".0f" << std::endl;
	else if (this->ScalarType == 2)
		std::cout << this->Float << printDotZero(static_cast<float>(this->Float)) << "f" <<  std::endl;
	else if (this->ScalarType == 3)
	{
		if (canConvertToFloat(this->Double))
			std::cout << static_cast<float>(this->Double) 
					<< printDotZero(static_cast<float>(this->Double)) << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::printDouble(void)
{
	std::cout << "double: ";
	if (this->ScalarType == 0)
		std::cout << static_cast<double>(this->Char) << ".0" << std::endl;
	else if (this->ScalarType == 1)
		std::cout << static_cast<double>(this->Int) << ".0" << std::endl;
	else if (this->ScalarType == 2)
		std::cout << static_cast<double>(this->Float) 
				<< printDotZero(static_cast<double>(this->Float)) << std::endl;
	else if (this->ScalarType == 3)
		std::cout << this->Double << printDotZero(static_cast<double>(this->Double)) 
						<<std::endl;
}
