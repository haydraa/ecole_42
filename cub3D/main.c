#include "cub3D.h"

void	open_and_read_map(t_cub3D *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		printf("Error_map\n");
		exit(1);
	}
	get_map(data, argv);
	if (start_mlx(data) == 1)
		cub_free(data);
}

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
	ft_display(data.map);
	return (0);
}
