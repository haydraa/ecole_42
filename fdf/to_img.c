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

#include "fdf.h"

void in_img(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img,&data->bits_per_pixel, &data->line_length, &data->endian);
	while (i < data->core_x)
	{
		j = 0;
		while (j < data->core_y)
		{
			if (j != data->core_y - 1)
			{
				in_struct(data , i,j, 0);
				ft_dda(data);
			}	
			if (i != data->core_x - 1)
			{
				in_struct(data, i,j,1);
				ft_dda(data);
			}
			j++;
		}
		i++;
	}
   mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img,0,0);

}

void ft_dda(t_fdf *data)
{
	data->i = 0;
	color_rgb(data);
	zoom(data);
	isometric(&data->x0, &data->y0,data->z);
	isometric(&data->x1, &data->y1,data->z1);
	get_place(data);
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	if (abs(data->dx) > abs(data->dy))
		data->steps = abs(data->dx);
	else
		data->steps = abs(data->dy);
	data->xinc = (float)data->dx / data->steps;
	data->yinc = (float)data->dy / data->steps;
	data->X = data->x0;
	data->Y = data->y0;	
	while (data->i <= data->steps)
	{
		mlx_put(data ,data->X, data->Y, data->color);
		data->X += data->xinc;
		data->Y += data->yinc;
		data->i++;
	}
}

void open_win(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if(data->mlx_ptr == NULL)
		return ;

	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	in_img(data);
	mlx_hook(data->win_ptr , 17, 0L, &ft_close ,data);
	mlx_loop_hook(data->mlx_ptr,&handle_no_even,data);
	mlx_key_hook(data->win_ptr,&handle_input,data);
	mlx_loop(data->mlx_ptr);
	//mlx_destroy_display(data->mlx_ptr);
//	free(data->mlx_ptr);
}

void	mlx_put(t_fdf *data, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr+(y * data->line_length + x * (data->bits_per_pixel/8));
		*(unsigned int*)dst = color;
	}
}
