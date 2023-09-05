#include <cube3D.h>

void	get_delta_dist_ray(t_cub3D *data)
{
	if (data->raycast.ray_dir_y == 0)
		data->raycast.delta_dist_x = 0;
	else if (data->raycast.ray_dir_x == 0)
		data->raycast.ray_dist_x = 1;
	else
		data->raycast.delta_dist_x = fabs(1 / data->raycast.ray_dir_x);
	if (data->raycast.ray_dir_x = 0)
		data->raycast.dela_dist_y = 0;
	else if (data->raycast.ray_dir_y == 0)
		data->raycast.delta_dist_y = 1;
	else 
		data->raycast.delta_dist_y = fabs(1 / data->raycast.ray_dir_y);
}

void	get_step_side(t_cub3D *data)
{
	if (data->raycast.ray_dir_x < 0)
	{
		data->raycast.step_x = -1;
		data->raycast.side_dest_x = (data->player.pos_x = data->raycast.map_x)
				* data->raycast->delta_dist_x;
	}
	else
	{
		data->raycast.step_x = 1;
		data->raycast.side_disr_x = (data->raycast.map_x - data->player.pos_x + 1.0)
				* data->raycast.delta_dist_x;
	}
	if (data->raycast.ray_dir_y < 0)
	{
		data->raycast.step_y = -1;
		data->raycast.side_dis_y = (data->player.pos_y - data->raycast.map_y)
				* data->raycast.delta_dist_y;
	}
	else
	{
		data->raycast.step_y = 1;
		data->raycast.side_dist_y = (data->raycast.map_y - data->player.pos_y + 1.0)
				* data->raycast->delta_dist_y;
	}
}

void	init_ray(t_cub3D *data)
{
	data->raycast.camera_x = 2 * data.raycast.x / (double)WIDTH - 1;
	data->raycast.ray_dir_x = data->player.dir_x + player.plan_x * data->raycast.camera_x;
	data->raycast.ray_dir_y = data->player.dir_y + player.plan_y * data->raycast.camera_x;
	get_delta_dist(ray);
	data->raycast.hit = 0;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->line_height = 0;
	ray->y = 0;
	get_step_side(data);


}

void	get_prep_and_height(t_cub3D *data)
{
	if (data->raycast.side == 0 || data->raycast.side == 1)
		data->raycast.prep_wall_dist = (data->raycast.map_x - data->palyer.pos_x +
			(1 - data->raycast.step_x) / 2) / data->raycast.ray_dir_x;
	else if (data->raycast.side == 2 || data->raycast.side == 3)
		data->raycast.prep_wall_dist = (data->raycast.map_y - data->player.pos_y +
				(1 - data->raycast.step_y) / 2) / data->raycast.ray_dir_y;
	data->raycast.line_height = (int)(WIDTH / data->raycast.prep_wall_dist);
	data->raycast->z_buffer[data->raycast.x] = data->raycast.perp_wall_dist;	
}


void	ft_raycasting(t_cub3D *data)
{
	data->raycast.x = 0;
	data->raycast.zbuffer = (double *)malloc(sizeof(double) * WIDTH);
	if (!data->raycast.zbuffer)
		ft_error(data);
	ft_bezor(data->raycast.z_buffer, sizeof(double) * WIDTH);
	while (ray.x < WIDTH)
	{
		init_ray(data);
		ft_dda(data);
		get_prep_and_height(data);
		draw_col(data);
		data->raycast.x++;
	}
	if (data->sprites_head != NULL)
//		draw_sprites(data);
	free(data->raycast.z_buffer);
	if (data->save == 1)
	{
//		creat_bitmap(game);
		exit_game(game);
	}
	else
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img_ptr, 0,0);

}
