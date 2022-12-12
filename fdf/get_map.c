#include "fdf.h"

int size_x(char *file)
{
	int x;
	char *line;
	char **num;
	int fd;
	int i;

	x = 0;
	i = 0;
	fd = open(file,O_RDONLY);
	line = get_next_line(fd);
	num = ft_split(line, ' ');
	while (num[i])
	{	
		i++;
	}

	close(fd);
	free(num);
	return i - 1;
}

int size_y(char *file)
{
	int y;
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
	}
	close(fd);
	return y;
}


int **malloc_map(char *file)
{
	int y;
	int x;
	int j;
	int **tab;
	j = 0;
	y = size_y(file);
	x = size_x(file);
	tab = (int**)ft_calloc(sizeof(int*), y);
	while (j < y)
	{
		tab[j] = (int *)ft_calloc(x, sizeof(int));
		j++;
	}
	return tab;
}

void fil_tab(int *tab, char *line, int x)
{
	char **num;
	int i;

	i = 0;
	num = ft_split(line,' ');
	while (num[i] && i < x)
	{
		tab[i] = ft_atoi(num[i]);
		i++;
	}
}

void to_tab(int fd, int **tab, char *file)
{
	int x;	
	int y;
	int i;
	char *line;

	i = 0;
	x = size_x(file);	
	y = size_y(file);
	while (i < y)
	{
		line = get_next_line(fd);
		fil_tab(tab[i], line, x);
		i++;
	}
//	dis(tab,file);
}
