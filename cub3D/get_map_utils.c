#include "cub3D.h"

void	cub_free(t_cub3D *data)
{
	int i;
	i = -1;
	while (data->map.map[++i])
		free(data->map.map[i]);
	free(data->map.map);
	close(data->fd);
}

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
			free(tab[i]);
	free(tab);
}

int	count_y(char **argv)
{
	int y;
	int fd;
	char *line;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line_check(line) == 0)
			break;
		free(line);
	}
	y++;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		y++;
	}
	close(fd);
	free(line);
	return (y);
}
	
int	texture_id(t_cub3D *data, char **tmp)
{
	int i;

	i = -1;
	if (ft_strcmp(tmp[0], "NO") == 0)
		data->texture.north = tmp[1];
	else if (ft_strcmp(tmp[0], "SO") == 0)
		data->texture.south = tmp[1];
	else if (ft_strcmp(tmp[0], "WE") == 0)
		data->texture.west = tmp[1];
	else if (ft_strcmp(tmp[0], "EA") == 0)
		data->texture.east = tmp[1];
	else
		return (1);	
	data->texture.index++;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (0);
}

int ft_count(char **tmp)
{
	int i;
	i = 0;

	while (tmp[i])
		i++;
	if (i == 1)
		return (-1);
	return (i);
}

void	get_color_F(t_cub3D *data, char *line)
{
	char *temp;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	line = ft_strtrim(temp , "F");
	tmp = ft_split(line, ',');
	i = ft_count(tmp);
	data->texture.f_color = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (tmp[++i])
		data->texture.f_color[i] = ft_strtrim(tmp[i], " ");	
	//data->texture.f_color[i] = NULL;
	free_tab(tmp);
	free(line);
	free(temp);	
}

void	get_color_C(t_cub3D *data, char *line)
{
	char *temp;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	line = ft_strtrim(temp , "C");
	tmp = ft_split(line, ',');
	i = ft_count(tmp);
	data->texture.c_color = malloc(sizeof(char *) * i + 2);
	i = -1;
	while (tmp[++i])
		data->texture.c_color[i] = ft_strtrim(tmp[i], " ");	
	//data->texture.c_color[i--] = NULL;
	free_tab(tmp);
	free(line);
	free(temp);	
}

int	get_colors(t_cub3D *data, char *line)
{
	char **tmp;	

	tmp = ft_split(line, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		if (ft_count(tmp) == -1)
		{
			free_tab(tmp);
			return (1);
		}
		else
		{
			free_tab(tmp);
			data->texture.index++;
			get_color_F(data,line);
		}
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{	
		if (ft_count(tmp) == -1)
		{
			free_tab(tmp);
			return (1);
		}
		else
		{
			free_tab(tmp);
			data->texture.index++;
			get_color_C(data,line);
		}
	}
	return (0);
}

int line_check(char *line)
{
	if (line[0] == '1' || line[0] == ' ')
	{
		if (line[ft_strlen(line) - 2] == 32 
			||line[ft_strlen(line) - 2] == '1')
				return (0);
	}
	return (1);
}

int get_map_texture(t_cub3D *data, char **argv)
{
	int i;
	char **tmp;
	(void) argv;

	data->index = 0;
	i = 0;
	data->texture.c_color = NULL;
	data->texture.f_color = NULL;
	
	while (1)
	{
		data->map.line = get_next_line(data->fd);
		if (!data->map.line)
			return (3);
		if (line_check(data->map.line) == 0)
			return (2);
		tmp = ft_split(data->map.line, ' ');
		if (!tmp[1] && data->map.line[0] !=  '\n')
			return (1);
		texture_id(data, tmp);
		if (get_colors(data, data->map.line) == 1)
		{
			printf("Error colors\n");
			exit (1);
		}
		free(data->map.line);
		data->index++;
		i++;
	}
	if (data->texture.c_color == NULL || data->texture.f_color == NULL)
	{
		printf("Error colors\n");
		//free;
		exit(1);
	}
	return (0);
}

