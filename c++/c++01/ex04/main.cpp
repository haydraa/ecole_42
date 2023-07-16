#include "sed.hpp"

void	replace_line(std::string& line, std::string s1, std::string s2)
{
	size_t pos;

	pos = line.find(s1);
	if (pos == 0)
		return;
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1 , pos + s2.length());
	}
}

int read_file(std::ifstream& infile, char **argv)
{
	std::string line;
	std::string	line2;
	std::ofstream outfile("end_file");

	if (outfile.is_open())
	{
		while (std::getline(infile, line))
		{
			replace_line(line, argv[2], argv[3]);
			outfile << line << std::endl;	
		}
		outfile.close();
		infile.close();
		return (0);
	}
	return (1);


}

int open_file(char **argv)
{
	std::ifstream	infile;
	infile.open(argv[1]);
	if (infile.is_open())
	{
		if (read_file(infile ,argv) == 1)
		{
			infile.close();
			return (1);
		}
	}
	else
		return (1);
	return (0);
}


int main(int argc, char **argv)
{
	if (argc > 4 || argc < 4)
	{
		std::cout << "Argument number is incorrect" << std::endl;
		return (1);
	}
	else
	{
		if (open_file(argv) == 1)
		{
			std::cout << "Error file" << std::endl;
			return (1);
		}
	}
	return (0);
}
