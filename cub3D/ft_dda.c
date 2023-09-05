#include "cub3D.h"

void	get_wall_dist(t_cub3D *data)
{
	if (data->raycast.side_dist_x < data->raycast.side_dist_y)
	{
		data->raycast.side_dist_x += data->raycast.delta_dist_x;
		data->raycast.map_x += data->raycast.step_x;
		if (data->raycast.step_x == -1)
			data->raycast.side = 0;
		else
			data->raycasti.side = 1;
	}
	else
	{
		data->raycast.side_dist_y += data->raycast.delta_dist_y;
		data->raycast.map_y _+= data->raycast.step_y;
		if (data->raycast.step_y == -1)
			data->raycast.side = 2;
		else
			data->raycast.side = 3;
	}
}

void	ft_dda(t_cub3D *data)
{
	while (data->raycast.hit != 1)
	{
		get_wall_dist(data)
		if (data->map.map_int[data->raycast.map_y][data->raycast.map_x] >= 1 &&
				data->map.map_init[data->raycast.map_y][data->raycast.map_x] != 2)
				ray->hit = 1;
		else if (data->map.map[data->raycast.map_y][data->raycast.map_y] == 2)
			ft_sprite(data);
	}
}

