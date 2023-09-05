#include "cub3D.h"

void	set_wall(t_cub3D *data)
{
	int	text_x;
	t_ima
}

void	draw_col(t_cub3D *data)
{
	data->raycast.draw_start = -data->raycast.line_height / 2 + WIDTH / 2;
	data->raycast.draw_end = data->line_height / 2 + HIEGHT / 2;
	if (data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	if (data->raycast.draw_end >= HEIGTH)
		data->raycast.draw_end = HEIGHT - 1;
	if (data->raycast.side == 0 || data->raycast.side == 1)
		data->raycast.wall_x = data->player.pos_y 
			+ data->raycast.prep_wall_dist * data->raycast->ray_dir_y;
	else
		data->raycast.wall_x = data->player.pos_x
				+ data->raycast.prep_wall_dist * data->raycast.ray_dir_x;
	data->raycast.wall_x -= floor(data->raycast.wall_x);
	set_wall(data);
	set_color_image(data);
}
