/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:27 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:53:37 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_close(t_cub3D *data)
{
	free_image(data, data->north);
	free_image(data, data->south);
	free_image(data, data->west);
	free_image(data, data->east);
	free_image(data, data->image);
	free(data->player);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	the_ultimate_free(data);
	return (0);
}

void	mlx_put(t_image *image, int x, int y, int color)
{
	unsigned char	*src;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	image->img_data[y * image->size_line + x * image->bpp / 8] = r;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 1] = g;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 2] = b;
}

int	handel_input(t_cub3D *data)
{
	if (data->keys.key_w == 1)
		move_forward(data);
	else if (data->keys.key_s == 1)
		move_backward(data);
	else if (data->keys.key_d == 1)
		move_left(data);
	else if (data->keys.key_a == 1)
		move_right(data);
	else if (data->keys.right_arr == 1)
		rotate_right(data->player);
	else if (data->keys.left_arr == 1)
		rotate_left(data->player);
	else if (data->keys.key_esc == 1)
		ft_close(data);
	return (0);
}

int	have_a_toure(t_cub3D *data)
{
	handel_input(data);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	ft_raycasting(data);
	return (0);
}

int	start_mlx(t_cub3D *data)
{
	init_function(data);
	ft_raycasting(data);
	mlx_hook(data->mlx.win_ptr, 17, 0L, &ft_close, data);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx.mlx_ptr, &have_a_toure, data);
	mlx_loop(data->mlx.mlx_ptr);
	return (0);
}
