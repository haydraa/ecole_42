#include "push_swap.h"

char	*len_args(int argc, char **argv)
{	
	int i;
	char *all;
	int x;
	int j;
	
	j = 0;
	i = 1;
	x = 0;
	if (argc == 1)
		return NULL;
	while (i < argc)
	{	
		x = x + ft_strlen(argv[i]);
		j++;
		i++; 
	}
	all = malloc(sizeof(char) * (x + j + 1));
	return all;
}

char 	*join(int argc,	char **argv)
{
	int i;
	char *all_args;
	int x;
	int y;

	y = 0;
	i = 1;
	all_args = len_args(argc,argv);
	while (i <  argc)
	{
		x = 0;
		if (ft_check_arg(argv[i]) == 0)
		{
			free(all_args);
			return NULL;
		}
		while (argv[i][x])
		{
			all_args[y] = argv[i][x];
			x++;
			y++;
		}
		all_args[y] = ' ';
		i++;
	}
	return all_args;
}

