#include "cub3D.h"

void	ft_display(char **tab1)
{
	int i = -1;
	while (tab1[++i])
	{
		printf("%s", tab1[i]);
		printf("\n");
	}
}


void	open_and_read_map(t_cub3D *data, char **argv)
{
	null_init(data);
	if (get_map(data, argv) == 1)
	{
		//error msg;
		//free;
		return;
	}
	data->player = init_player();
	data->image = image_init();
	texture_init(data);
	data->save = 1;
	//ft_display(data->map.map);
	get_pos_player(data);
//	if (start_mlx(data) == 1)
//		cub_free(data);
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
