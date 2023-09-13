#include "cub3D.h"

void	move_forward(t_cub3D *data)
{
	if (data->map.map_int[(int)(data->player->pos_y)][(int)(data->player->pos_x
							+ data->player->dir_x * data->player->mov_speed)] == 0)
			set_position_init(data, data->player->dir_y * data->player->mov_speed, 0);
	if (data->map.map_int[(int)(data->player->pos_y + data->player->dir_y
						   * data->player->mov_speed)][(int)(data->player->pos_x)] == 0)
			set_position_init(data, 0, data->player->dir_y * data->player->mov_speed);
}

void	move_backward(t_cub3D *data)
{
	if (data->map.map_int[(int)(data->player->pos_y)]
		[(int)(data->player->pos_x - data->player->dir_x * data->player->mov_speed)] == 0)
		set_position_init(data, -(data->player->dir_x * data->player->mov_speed), 0);
	if (data->map.map_int[(int)(data->player->pos_y - data->player->dir_y
			* data->player->mov_speed)][(int)(data->player->pos_x)] == 0)
		set_position_init(data, 0, -(data->player->dir_y * data->player->mov_speed));
}

void	move_right(t_cub3D *data)
{
	if (data->map.map_int[(int)(data->player->pos_y)]
	[(int)(data->player->pos_x + data->player->plan_x
			* data->player->mov_speed)] == 0)
		set_position_init(data, data->player->plan_x * data->player->mov_speed, 0);
	if (data->map.map_int[(int)(data->player->pos_x 
	 + data->player->plan_y * data->player->mov_speed)]
		[(int)data->player->pos_x] == 0)
		set_position_init(data, 0,data->player->plan_y * data->player->mov_speed);
}
void	move_left(t_cub3D *data)
{
	if (data->map.map_int[(int)(data->player->pos_y)]
	[(int)(data->player->pos_x - data->player->plan_x
			* data->player->mov_speed)] == 0)
		set_position_init(data, -(data->player->plan_x * data->player->mov_speed), 0);
	if (data->map.map_int[(int)(data->player->pos_x 
	 - data->player->plan_y * data->player->mov_speed)]
		[(int)data->player->pos_x] == 0)
		set_position_init(data, 0, -(data->player->plan_y * data->player->mov_speed));

}

