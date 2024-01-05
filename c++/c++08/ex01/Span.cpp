#include "Span.hpp"

Span::Span(unsigned int N): Size(N)
{
	std::cout << "Constructor Called" << std::endl;
}

Span::Span(void): Size(0)
{
	std::cout << "COnstructor For Default Called" << std::endl;
}

Span::Span(const Span &init): Size(init.Size), vec(init.vec)
{
	std::cout << "Constructor  For Copy Called" << std::endl;
}

Span::~Span(void)
{	
	std::cout << "Destructor Called" << std::endl;
}

Span &Span::operator=(const Span &init)
{
	if (this != &init)
	{
		this->vec = init.vec;
		this->Size = init.Size;
	}
	return (*this);
}

void	Span::addNumber(int x)
{
	if (this->vec.size() < this->Size)
		this->vec.push_back(x);
	else
		throw Full();
}

unsigned int Span::shortestSpan() const
{
	std::vector<int> tmp;
	int (*iabs)(int) = &std::abs;
	if (this->vec.size() <= 1)
		throw Empty();
	std::adjacent_difference(this->vec.begin(),
		this->vec.end(), std::back_inserter(tmp));
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs);
	return *min_element(tmp.begin(), tmp.end());
}

unsigned int Span::longestSpan()const
{
	std::vector<int> tmp;

	int(*iabs)(int) = &std::abs;
	if (this->vec.size() <= 1)
		throw Empty();
	std::adjacent_difference(this->vec.begin(), 
		this->vec.end(), std::back_inserter(tmp));
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs);
	return *max_element(tmp.begin(), tmp.end());
}

void	Span::addNumber(const std::vector<int>::iterator
	&begin, const std::vector<int>::iterator &end)
{
	int distance = std::distance(begin, end);
	if (distance + this->vec.size() > this->Size)
	{
		this->vec.insert(this->vec.end(), begin, begin
				+ (this->Size - this->vec.size()));
		throw Full();
	}
	else
		this->vec.insert(this->vec.end(), begin, end);
}

const char *Span::Full::what() const throw()
{
	return ("Container Full");
}

const char *Span::Empty::what() const throw()
{
	return ("container Empty");
}