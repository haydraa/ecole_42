/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:42 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:44:47 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	in_img(t_fdf *data)
{
	data->x = 0;
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->e);
	while (data->x < data->core_x)
	{
		data->y = 0;
		while (data->y < data->core_y)
		{
			if (data->y != data->core_y - 1)
			{
				in_struct(data, data->x, data->y, 0);
				ft_dda(data);
			}	
			if (data->x != data->core_x - 1)
			{
				in_struct(data, data->x, data->y, 1);
				ft_dda(data);
			}
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	ft_dda(t_fdf *data)
{
	data->i = 0;
	color_rgb(data);
	zoom(data);
	isometric(&data->x0, &data->y0, data->z);
	isometric(&data->x1, &data->y1, data->z1);
	get_place(data);
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	if (abs(data->dx) > abs(data->dy))
		data->steps = abs(data->dx);
	else
		data->steps = abs(data->dy);
	data->xinc = (float)data->dx / data->steps;
	data->yinc = (float)data->dy / data->steps;
	data->big_x = data->x0;
	data->big_y = data->y0;
	while (data->i <= data->steps)
	{
		mlx_put(data, data->big_x, data->big_y, data->color);
		data->big_x += data->xinc;
		data->big_y += data->yinc;
		data->i++;
	}
}

void	open_win(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	in_img(data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_close, data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_even, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop(data->mlx_ptr);
}

void	mlx_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
