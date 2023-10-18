#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc > 1 && argc < 3)
	{
		BitcoinExchange Btc;

		if (Btc.GetCsvData() != 0)
			return 1;
		if (Btc.dataInpute(argv[1]) != 0)
			return 1;
		while (std::getline(file, line))
		{
			splitDateValue(line);
			try{
			 	Btc.CheckDate(this->date);
				Btc.Checkvalue(this->value);
				Btc.lastCheck(this->priceMap);
			}
			catch (std::exception &e)
			{
				std::cout << e.what << std::endl;
			}
		}
	}
	else
		std::cout << "Error: Argumant" << std::endl;
	return (-1);
}
