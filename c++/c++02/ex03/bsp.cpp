#include "Point.hpp"

float	area_calc(const Point& a, const Point& b, const Point & c)
{
	float x1, y1;
	float x2, y2;
	float x3, y3;

	x1 = a.getX().toFloat();
	y1 = a.getY().toFloat();
	x2 = b.getX().toFloat();
	y2 = b.getY().toFloat();
	x3 = c.getX().toFloat();
	y3 = c.getY().toFloat();
	
	return(std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
		
	float ABC, PBC, APC, ABP;

	ABC = area_calc(a, b, c);
	PBC = area_calc(point, b, c);
	APC = area_calc(a, point, c);
	ABP = area_calc(a, b, point);
	
	if (ABC == PBC + APC + ABP)
		return (true);
	else
		return (false);
}

