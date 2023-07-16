#include "Harl.hpp"

int main(void)
{
	Harl comp;

	comp.complain("DEBUG");
	comp.complain("INFO");
	comp.complain("WARNING");
	comp.complain("ERROR");
	comp.complain("NOTHING");
}
