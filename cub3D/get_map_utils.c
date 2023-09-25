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
	{
		free_tab(tmp);
		return (1);	
	}
	data->texture.index++;
	free_tab(tmp);
	return (0);
}

int ft_count(char **tmp, int x)
{
	int i;
	i = 0;

	while (tmp[i])
		i++;
	if ((i <= 3 || i > 4) && x != 1)
		return (-1);
	return (i);
}

void	get_color_F(t_cub3D *data, char *line)
{
	char *temp;
	char *temp2;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "F");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	data->texture.f_color = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (tmp[++i])
		data->texture.f_color[i] = ft_strtrim(tmp[i], " ");	
	data->texture.f_color[i] = NULL;
	free_tab(tmp);
	free(temp2);
	free(temp);	
}

void	get_color_C(t_cub3D *data, char *line)
{
	char *temp;
	char *temp2;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "C");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	data->texture.c_color = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (tmp[++i])
		data->texture.c_color[i] = ft_strtrim(tmp[i], " ");	
	data->texture.c_color[i--] = NULL;
	free_tab(tmp);
	free(temp);
	free(temp2);
}

int	get_colors(t_cub3D *data, char *line)
{
	char **tmp;	

	tmp = ft_split(line, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		if (ft_count(tmp, 0) == -1)
		{
			printf("Flour_color has a problem\n");
			free_tab(tmp);
			free_tab(data->map.map);
			free(line);
			return (3);
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
		if (ft_count(tmp, 0) == -1)
		{
			printf("Clour_color has a problem\n");
			free_tab(tmp);
			free_tab(data->map.map);
			free(line);
			return (3);
		}
		else
		{
			free_tab(tmp);
			data->texture.index++;
			get_color_C(data,line);
		}
	}
	else
		free_tab(tmp);
	return (0);
}

int line_check(char *line)
{
	char *temp;
	char *temp2;
	
	temp = ft_strtrim(line, " ");
	temp2 = ft_strtrim(temp, "\t");
	if (temp2[0] == '1')
	{
		if (temp2[ft_strlen(temp2) - 2] == '1')
		{
			free(temp);
			free(temp2);
			return (0);
		}	
	}
	free(temp);
	free(temp2);
	return (1);
}

int get_map_texture(t_cub3D *data, char **argv)
{
	int i;
	char **tmp;
	char *line;
	int fd;
	
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		exit(1);
		free_tab(data->map.map);
	}
	data->index = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (3);
		if (line_check(line) == 0)
			return (2);
		tmp = ft_split(line, ' ');
		texture_id(data, tmp);
		if (get_colors(data, line) == 3)
		{
			while (1)
			{
				line = get_next_line(fd);
				if (!line)
					exit (1);
				free(line);
			}
		}
		free(line);
		data->index++;
		i++;
	}
	last_check(data);
	close (fd);
	return (0);
}

