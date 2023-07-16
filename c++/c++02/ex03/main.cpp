#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point A(0.f, 0.f); 
	Point B(10.f, 30.f); 
	Point C(20.f, 0.f); 
	Point P(10.f, 15.f);
	
	if (bsp(A, B, C, P) == true)
		std::cout << "point is in the triangle" << std::endl;
	else 
		std::cout << "point is not in the triangle" << std::endl;
}
