/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:58 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 16:47:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	textur_put(t_cub3D *data, t_image *texture)
{
	int	d;

	d = data->raycast.y * texture->size_line - HIEGHT * texture->size_line / 2
		+ data->raycast.line_height * texture->size_line / 2;
	data->raycast.text_y = ((d * texture->height) / data->raycast.line_height)
		/ texture->size_line;
		data->image->img_data[data->raycast.y * data->image->size_line
			+ data->raycast.x * data->image->bpp / 8]
			= texture->img_data[data->raycast.text_y * texture->size_line
			+ data->raycast.text_x * (texture->bpp / 8)];
	data->image->img_data[data->raycast.y * data->image->size_line
		+ data->raycast.x * data->image->bpp / 8 + 1]
		= texture->img_data[data->raycast.text_y * texture->size_line
		+ data->raycast.text_x * (texture->bpp / 8) + 1];
	data->image->img_data[data->raycast.y * data->image->size_line
		+ data->raycast.x * data->image->bpp / 8 + 2]
		= texture->img_data[data->raycast.text_y * texture->size_line
		+ data->raycast.text_x * (texture->bpp / 8) + 2];
}

void	set_textur_to_image(t_cub3D *data, t_image *texture)
{
	data->raycast.y = data->raycast.draw_start;
	while (data->raycast.y <= data->raycast.draw_end)
	{
		textur_put(data, texture);
		data->raycast.y++;
	}
}

void	set_wall(t_cub3D *data)
{
	int		text_x;
	t_image	*texture;

	texture = data->west;
	if (data->raycast.side == 1)
		texture = data->east;
	else if (data->raycast.side == 2)
		texture = data->north;
	else if (data->raycast.side == 3)
		texture = data->south;
	text_x = (int)(data->raycast.wall_x * (double)texture->width);
	if ((data->raycast.side == 0 || data->raycast.side == 1)
		&& data->raycast.ray_dir_x > 0)
		text_x = texture->width - text_x - 1;
	if ((data->raycast.side == 2 || data->raycast.side == 3)
		&& data->raycast.ray_dir_y < 0)
		text_x = texture->width - text_x - 1;
	data->raycast.text_x = text_x;
	set_textur_to_image(data, texture);
}

void	set_color_image(t_cub3D *data)
{
	int	y;

	y = 0;
	while (y < data->raycast.draw_start)
		mlx_put(data->image, data->raycast.x, y++, data->c_color);
	y = data->raycast.draw_end + 1;
	while (y < WIDTH)
		mlx_put(data->image, data->raycast.x, y++, data->f_color);
}

void	draw_col(t_cub3D *data)
{
	data->raycast.draw_start = -data->raycast.line_height / 2 + WIDTH / 2;
	data->raycast.draw_end = data->raycast.line_height / 2 + HIEGHT / 2;
	if (data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	if (data->raycast.draw_end >= HIEGHT)
		data->raycast.draw_end = HIEGHT - 1;
	if (data->raycast.side == 0 || data->raycast.side == 1)
		data->raycast.wall_x = data->player->pos_y
			+ data->raycast.prep_wall_dist * data->raycast.ray_dir_y;
	else
		data->raycast.wall_x = data->player->pos_x
			+ data->raycast.prep_wall_dist * data->raycast.ray_dir_x;
	data->raycast.wall_x -= floor(data->raycast.wall_x);
	set_wall(data);
	set_color_image(data);
}
