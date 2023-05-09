#include <iostream>
#include <cstring>

void	ft_putchar(char s)
{
	std::cout << s;
}	

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			ft_putchar(toupper(argv[i][j]));
			j++;
		}
		i++;
	}
	ft_putchar('\n'); 
	return 0;
}
