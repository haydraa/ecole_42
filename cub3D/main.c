#include "cub3D.h"

void	ft_display(char **tab)
{
	int i = 0;
	int y = 0;


	while (tab[i])
	{
		y = 0;
		while (tab[i][y])
		{
			printf("%c", tab[i][y]);
			y++;
		}
		i++;
	}
}
void	open_and_read_map(t_cub3D *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	data->fd2 = open(argv[1], O_RDONLY);
	if (data->fd < 0 || data->fd2 < 0)
	{
		printf("Error_file\n");
		exit(1);
	}
	if (get_map(data, argv) == 1)
	{
		//error msg;
		//free;
		return;
	}
	ft_display(data->map.map);
	if (get_pos_player(data) == 1)
	{
		//error msg;
		cub_free(data);
	}
	if (start_mlx(data) == 1)
		cub_free(data);
}


int main(int argc, char **argv)
{
	t_cub3D	data;
		
	if (argc < 2 || argc > 2)
	{
		printf("Error argument!\n");
		exit(1);
	}
	else
		open_and_read_map(&data, argv);
	return (0);
}
