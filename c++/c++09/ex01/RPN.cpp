#include "RPN.hpp"


RPN::RPN(void) : Input("")
{}

RPN::RPN(std::string input) ; Input(input)
{}

RPN::RPN(const RPN &init)
{
	if (this != &init)
		*this = init;
	return;
}

RPN &RPN::operator=(const RPN &init)
{
	if (this != &init)
		this->Stack = init.Stack;
	return (*this);
}

RPN::~RPN(void)
{}

int	CheckChar(char c)
{
	if (c == ' ')
		return 32;
	else if (c == '+' || c == '-' || c == '/' || c == '*')
		return 0;
	if (std::isdigits(c))
		return 0;
	return -1;
}


void	RPN::ToStack()
{
	int i;

	if (this->input.empty())
		throw Error();
	for (size_t i; i < this->input.size(); i++)
	{
		i = CheckChar(input[i]);
		if (i == 32)
			i++;
		else if (i == 0)
			// add to stack
		else
			throw Error();
	}
}



