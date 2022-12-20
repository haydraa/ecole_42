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


void malloc_map(t_fdf *data)
{
	int j;
	
	j = 0;
	data->core_y = size_y(data->file);
	data->core_x = size_x(data->file);
	data->tab = (int**)ft_calloc(sizeof(int*), data->core_y);
	while (j < data->core_y)
	{
		data->tab[j] = (int *)ft_calloc(data->core_x, sizeof(int));
		j++;
	}
}

void fil_tab(int *tab, char *line, int x)
{
	char **num;
	int i;
	int j;

	j = 0;
	i = 0;
	num = ft_split(line,' ');
	while (num[i] && i < x)
	{
		tab[i] = ft_atoi(num[i]);
		i++;
	}
	i = 0;
	while (num[i])
		i++;
	while (j < i)
	{
		free(num[j]);
		j++;
	}
	free(num);
}

void to_tab(int fd, t_fdf *data)
{
	int i;
	char *line;

	i = 0;
	while (i < data->core_y)
	{
		line = get_next_line(fd);
		fil_tab(data->tab[i] , line, data->core_x);
		i++;
	}
}
