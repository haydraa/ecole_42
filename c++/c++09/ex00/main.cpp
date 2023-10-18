#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::string line;
	std::ifstream file(argv[1]);

	if (argc > 1 && argc < 3)
	{
		BitcoinExchange Btc;
		if (Btc.GetCsvData() != 0)
			return 1;
	    if(!file.is_open())
		{
        	std::cerr << "Error: file" << std::endl;
	     	return 1;
	    }
	    else 
		{
	        std::getline(file, line);
	        if (line.compare("date | value") != 0)
	        {
	            std::cerr << "Error: Wronge First line" << std::endl;
	            return 1;
	        }
		}
		while (std::getline(file, line))
		{
			try
			{
				Btc.SplitDateValue(line);
			 	Btc.CheckDate();
				Btc.CheckValue();
				Btc.lastCheck();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	else
		std::cout << "Error: Argumant" << std::endl;
	return (-1);
}
