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


