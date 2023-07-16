# include "Point.hpp"

Point::Point():x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float x, const float y):x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point& init):x(init.getX()), y(init.getY())
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& init)
{
	(void) init;
	return (*this);
}

const Fixed&	Point::getY()const
{
	return (this->y);
}

const Fixed&	Point::getX()const
{
	return (this->x);
}

	


