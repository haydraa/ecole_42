#include "push_swap.h"

int ft_check_arg(char *arg)
{
	int i;
  
	i = 0;

	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (arg[i + 1] == '-' || arg[i + 1] == '+' || arg[i + 1] == ' ')
				return 0;	
		}
		else if ((arg[i] < '0' || arg[i] > '9'))
			return 0;
		i++;
	}	
	return 1;
}

int to_dob(char **tab)
{
	int i;
	int j;
	int x;

	x = 0;
	i = 0;
	j = 1;
	while (tab[x])
			x++;
	while (i < x)
	{
		j = 1;
		while (i + j < x)
		{
			if (ft_doubel(tab[i], tab[i + j]) == 0)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int ft_doubel(char *str, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] || s[j])
	{
		if (str[i] != s[j])
			return 1;
		i++;
		j++;
	}
	return 0;
}