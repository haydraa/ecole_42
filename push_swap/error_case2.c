#include "push_swap.h"

void join(char *dest, char *src, char space)
{
	int i;
	int len;


	len = ft_strlen(dest);	
	i = 0;
	if (len > 0)
	{
		dest[len] = space;
		len++;
	}
	while (src[i])
	{
		dest[len] = src[i];
		len++;
		i++;
	}
}

int check(char *src)
{
	int len;
	int x;
	int i;

	x = 0;
	len = ft_strlen(src);
	i = 0;
	while(src[x])
	{
		if (src[x] == ' ')
			i++;
		x++;
	}
	if (i == len)
		return 1;
	return 0;
}

char **split(char *all, int j)
{
	char **final;
	int i;
	
	i = 0;
	final = malloc(sizeof(char*) * j);
	
	while (i >= j)
	{
		
		
	}
	
	
}

int assembel(int argc, char **argv)
{
	int i;
	char *all;
	int x;
	int j;

	j = 1;
	i = 1;
	x = 0;
	while (i < argc)
	{
		if (check(argv[i]) == 1)
		{
			ft_printf("error\n");
			return 0;
		}
		x = x + ft_strlen(argv[i]);
		j++;
		i++; 
	}
	all = malloc(sizeof(char) * x + j + 1);
	i = 1;
	while (i < argc)
	{	
		join(all,argv[i], ' ');
			i++;
	}
	split(all, j);
	ft_printf("%s\n", all);
	return 0;
}
