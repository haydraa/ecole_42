#include "push_swap.h"

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

int ft_check_arg(char *arg)
  {
        int i;

        i = 0;
		while (arg[i] != '\0')
		{
			if (arg[i] == '-')
					i++;
			if (arg[i] < '0' || arg[i] > '9')
				return 0;
			i++;
		}	
		return 1;
}

int ft_assembel(int arg, char **arg1)
{
		int i;
		int j;

		i = 1;
		j = 2;
		while (i < arg && arg1[i])
		{
			if (ft_check_arg(arg1[i]) == 0)
			{	
				ft_printf("error\n");
				return 0;
			}
			i++;
		}
		i = 1;
		while (i < arg)
		{
			j = 2;
			while (j < arg)
			{
				if (ft_doubel(arg1[i],arg1[j]) == 0)
				{
					ft_printf("error\n");
					return 0;
				}
				j++;
			}
			i++;
		}
		return 0;
}
