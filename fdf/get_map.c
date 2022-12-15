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
	int j;
	t_tab tab;
	j = 0;
	tab.core_y = size_y(file);
	tab.core_x = size_x(file);
	tab.tab = (int**)ft_calloc(sizeof(int*), tab.core_y);
	while (j < tab.core_y)
	{
		tab.tab[j] = (int *)ft_calloc(tab.core_x, sizeof(int));
		j++;
	}
	return tab.tab;
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

void to_tab(int fd, t_tab tab, char *file)
{
//	int x;
//	int y;
	int i;
	char *line;

	i = 0;
	tab.core_x = size_x(file);	
	tab.core_y = size_y(file);
	while (i < tab.core_y)
	{
		line = get_next_line(fd);
		fil_tab(tab.tab[i], line, tab.core_x);
		i++;
	}
	dis(tab.tab,file);
}
