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

char	**assembel(int argc, char **argv)
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
			return NULL;
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
	argv = ft_split(all, ' ');
	i = 0;
	return argv;
}
