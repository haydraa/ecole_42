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

int error_string_exit(char *str)
{
	if (str)
		printf("%s", str);
	//free if needed
	exit(1);
	return (1);
}

void	resize_tab(t_cub3D *data, char *line)
{
	char **tmp;
	int i = 0;
	int j = 0;

	tmp = NULL;
	while (data->map.map[i])
		i++;
	if (!(tmp =(char**)malloc(sizeof(char *) * (i + 2))))
		the_ultimate_free(data);
	while (j < i)
	{
		tmp[j] = data->map.map[j];
		j++;
	}
	tmp[j++] = ft_strdup(line);
	tmp[j] = NULL;
	j = 0;
	free(data->map.tmp);
	data->map.tmp = NULL;
	free(data->map.map);
	data->map.map = tmp;
}

int get_map(t_cub3D *data, int fd)
{
	int i;
	char *line;

	i = 0;
	if (!(data->map.map = (char**)malloc(sizeof(char*) * 2)))
		the_ultimate_free(data);
	data->map.map[0] = ft_strdup(data->map.tmp);
	data->map.map[1] = NULL;
	free(data->map.tmp);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line_check(line, data) == 0)
			resize_tab(data, data->map.tmp);
		else
		{
			data->map.map_index++;
			free(line);
			break;
		}
		free(line);
	}
	return (0);
}

int	get_all(t_cub3D *data, char ** argv)
{
	char *line;
	int fd;
	
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error_string_exit("FILE ERROR\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		get_colors(data, line);
		texture_id(data,line);	
		if (line_check(line, data) == 0)
		{
			if (data->map.map_index == 0)
				get_map(data, fd);
			else
			{
				free(data->map.tmp);
				data->map.tmp = NULL;
			}
		}
		free(line);
	}		
	close(fd);
	return (0);
}

