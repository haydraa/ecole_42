#include "cub3D.h"

void	set_postion(t_cub3D *data)
{
	if (data->player->dir == '0')
	{
		printf("NO direction to player\n");
		// free ;
		exit(1);
	}
	else if (data->player->dir == 'N' || data->player->dir == 'S')
	{
		data->player->dir_x = 0;
		if (data->player->dir == 'N')
			data->player->dir_y = -1;
		else 
			data->player->dir_y = 1;
		if (data->player->dir == 'N')
			data->player->plan_x = 0.66;
		else
			data->player->plan_x = -0.66;
		data->player->plan_y = 0;
	}
	else if (data->player->dir == 'W' || data->player->dir == 'E')
	{
		data->player->dir_y = 0;
		if (data->player->dir == 'W')
			data->player->dir_x = -1;
		else 
			data->player->dir_x = 1;
		if (data->player->dir == 'W')
			data->player->plan_y = 0.66;
		else
			data->player->plan_y = -0.66;
		data->player->plan_x = 0;
	}
}


void	get_pos_player(t_cub3D *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' 
				|| data->map.map[i][j] == 'E' 
				|| data->map.map[i][j] == 'W' 
				|| data->map.map[i][j] == 'S')
			{
				data->player->dir = data->map.map[i][j];
			}
			j++;
		}
		i++;
	}
	set_postion(data);
}

t_player	*init_player(void)
{
	t_player *player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
	{
		printf("malloc failed\n");
		exit (1);
	}
	player->pos_x = 0.5;
	player->pos_y = 0.5;
	player->dir_x = 0.;
	player->dir_y = 0.;
	player->mov_speed = 0.17;
	player->rot_speed = 0.12;
	player->plan_x = 0.;
	player->plan_y = 0.;
	player->dir = '0';
	return (player);
}
