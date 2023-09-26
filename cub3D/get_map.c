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
			&& line[i] != ' ' && line[i] != '2')
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
	char *temp;
	char *temp2;
	int x;
	
	x = 0;
	temp = ft_strtrim(line, " ");
	temp2 = ft_strtrim(temp, "\t");
	free(temp);
	temp = ft_strtrim(temp2, "\n");
	index = 0;
	len = ft_strlen(temp);
	data->map.map[i] = malloc(sizeof(char) * len + 1);
	while(temp[index])
	{
		data->map.map[i][x] = temp[index];
		index++;
		x++;
	}
	data->map.map[i][x] = '\0';
	free(temp);
	free(temp2);
}

int	calcul_nbr(char *line)
{
	int i;
	char *str;

	str = ft_strtrim(line , " ");
	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	get_map(t_cub3D *data, char ** argv)
{
	int i;
	char *line;
	int fd;
	int x;

	i = 0;
	data->map.y_map = count_y(argv);
	if ((fd = open(argv[1], O_RDONLY)) < 0) 
	{
		exit(1);
		//free, test;	
	}
	if(!(data->map.map = malloc(sizeof(char *) * (data->map.y_map + 1))))
		exit(0);
	//free when problem ocure
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		x = line_check(line);
		if (x == 0)
		{
			malloc_and_fill_tab(line , i, data);
			i++;
		}
		else if (x == 1)
		{
			printf("Error inside the Map\n");
		//	free();
			while(1)
			{
				line = get_next_line(fd);
				if (!line)
					exit(1);
				free(line);
			}
		}
		free(line);
	}
	last_check(data, 1);
	data->map.map[i] = NULL;
	if (get_map_texture(data, argv) == 1)
			return (1);
	ft_color_init(data);
	close (fd);
	return (0);
}

