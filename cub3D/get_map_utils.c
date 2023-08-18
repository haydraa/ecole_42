#include "cub3D.h"

void	cub_free(t_cub3D *data)
{
	int i;
	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	close(data->fd);
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
		if (!line)
			break ;
		free(line);
		y++;
	}
	close(fd);
	free(line);
	return (y);
}

void	texture_id(t_cub3d *data, char **tmp)
{
	int i;

	i = -1;
	if (ft_strcmp(tmp[0], "NO") == 0)
		data->textur.north = tmp[1];
	else if (ft_strcmp(tmp[0], "SO") == 0)
		data->textur.south = tmp[1];
	else if (ft_strcmp(tmp[0], "WE") == 0)
		data->textur.west = tmp[1];
	else if (ft_strcmp(tmp[0], "EA") == 0)
		data->textur.east = tmp[1];
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

int	get_color(t_cub3D *data)
{
	int i;
	char tmp;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line[0] == 'F')
		{
			tmp = ft_split(line, ' ');
			if (!tmp[1])
			{
				free(line);
				free(tmp[0]);
				free(tmp);
			}
			data->texture.flour_color = tmp[1];
			i++;
		}
		if (line[0] == 'C')
		{	
			tmp = ft_split(line, ' ');
			if (!tmp[1])
			{
				free(line);
				free(tmp[0]);
				free(tmp);
			}
			data->texture.celing_color = tmp[1];
			i++;
		}
		free(line);
	}
	close(fd);
}

int get_map_textur(t_cub3D *data, char **argv)
{
	int i;
	char *line;
	char **tmp;

	data->map.index = 0;
	i = 0;
	while (i < 4)
	{
		line = get_next_line(data->fd);
		if (line[0] == '\n')
			return (1);
		tmp = ft_splite(line, ' ');
		if (!tmp[1])
			return (1);
		put_in_place(data, tmp);
		free(line);
		index++;
		i++;
	}
	if (get_colors(data) == 1);
		return (1);
	return (0);
}

