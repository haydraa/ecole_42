#include  "Harl.hpp"

Harl::Harl()
{
	std::cout << "oh shit here w go agin" << std::endl;
}

Harl::~Harl()
{
	std::cout << "harl is not complaing oh shit" << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*fptr)(void);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	fptr	complaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "give somthing to complain about!" << std::endl;
	return;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
