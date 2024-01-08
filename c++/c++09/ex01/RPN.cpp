#include "RPN.hpp"


RPN::RPN(void) : Input("")
{}

RPN::RPN(std::string input) : Input(input)
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

int	CheckChar(std::string input, size_t i)
{
	if (input[i] == ' ')
		return 32;
	else if (input[i] == '+' || input[i] == '-' 
			|| input[i] == '/' || input[i] == '*')
		return 2;
	else if (i < input.size())
	{
		if (std::isdigit(input[i]) && (!std::isdigit(input[i + 1])))
			return 0;
	}
	else 
		if (std::isdigit(input[i]))
			return 0;
	return -1;
}

void	RPN::Print()
{
	int upper = Stack.top();
	Stack.pop();
	if (!Stack.empty())
		throw ErorrCalcul();
	std::cout << upper << std::endl;	
}

int	Math(char c, std::stack<int> &Stack)
{
	int upper1 = Stack.top();
	Stack.pop();
	if (Stack.empty())
		return -1;
	int upper2 = Stack.top();
	Stack.pop();

	if (c == '+')
		Stack.push(upper2 + upper1);
	else if (c == '-')
		Stack.push(upper2 - upper1);
	else if (c == '*')
		Stack.push(upper2 * upper1);
	else if (c == '/')
	{
		if (upper1 == 0)
			return -1;
		Stack.push(upper2 / upper1);
	}
	return 0;
}


void	RPN::ToStack()
{
	int x;
	int index = 0;
	if (this->Input.empty())
		throw Erorr();
	for (size_t i = 0; i < this->Input.size(); i++)
	{
		x = CheckChar(this->Input, i);
		if (x == 32)
			i++;
		x = CheckChar(this->Input, i);
		if (x == 0)
		{
			this->Stack.push(Input[i] - '0');
			index++;
		}
		else if (x == 2 && index > 1)
		{
			if (index == 1)
				throw (ErorrCalcul());
			else
				if (Math(Input[i], this->Stack) == -1)
					throw (ErorrCalcul());
		}
		else
			throw Erorr();
	}
}

const char* RPN::Erorr::what() const throw()
{
	return ("Error Argument");
}

const char *RPN::ErorrCalcul::what() const throw()
{
	return ("You Have A Problem Inside The Argment");
}