#include "cub3D.h"

int	check_caracter(char *line)
{
	int i;
	int len;

	len = ft_strlen(line);
	i = 0;
	while (line[i] != '\n')
	{
		while ((line[i] >= 9 && line[i] <= 11) || line[i] == ' ')
			i++;
		if (line[i] != 'N' && line[i] != 'S' 
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] !=  '1' 
			&& line[i] != '0' && line[len] != '\n'
			&& line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	first_check(char *line , int i, t_cub3D *data)
{
	int x;
	int len;

	x = 0;
	if (check_caracter(line) == 1)
		return (1);
	if(i == 0 || i == data->map.y_map)
	{
		while (line[x])
		{
			while ((line[x] >= 9 && line[x] <= 11) || line[x] == ' ')
				x++;
			if (line[x] != '1')
			{
				if (line[x] == '\n' || line[x] == '\0')
					return (0);
				else
					return (1);
			}
				x++;
		}
	}
	else
	{
		len = ft_strlen(line);
		while ((line[x] >= 9 && line[x] <= 11) || line[x] == ' ')
				x++;
		if (line[x] != '1' && line[len - 2] != '1')
			return (1);
	}
	return (0);
}

void	malloc_and_fill_tab(char *line, int i, t_cub3D *data)
{
	int len;
	int index;
	int x;
	
	x = 0;
	index = 0;
	len = ft_strlen(line);
	if (first_check(line, i, data) == 1)
	{
		free(data->map.map);
		close(data->fd);
		printf("Error inside the map\n");
		exit(1);
	}
	else
	{
		data->map.map[i] = malloc(sizeof(char) * len);
		while(line[index])
		{
			if(line[index] == '\n')
				break ;
			data->map.map[i][x] = line[index];
			index++;
			x++;
		}
		data->map.map[i][x++] = '\0';
	}
}


int	get_map(t_cub3D *data, char ** argv)
{
	int i;
	char *line;

	i = 0;
	if (get_map_texture(data, argv) == 1)
			return (1);
	data->map.y_map = count_y(argv);
	data->map.map = malloc(sizeof(char *) * data->map.y_map + 1);
	while(1)
	{
		while (data->map.index-- > 0)
		{
			line = get_next_line(data->fd2);
			free(line);
		}
		line = get_next_line(data->fd2);
		if (!line)
			break;
		malloc_and_fill_tab(line , i, data);
		free(line);
		i++;
	}
	data->map.map[data->map.y_map + 1] = NULL;
	free(line);
	return (0);
}
