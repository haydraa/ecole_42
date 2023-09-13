/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:33 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:44:36 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_even(void *data)
{
	(void) data;
	return (0);
}

int	ft_close(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	the_free(data);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	the_key(int keysym, t_fdf *data)
{
	if (keysym == 119)
		data->shift_y -= 10;
	if (keysym == 115)
		data->shift_y += 10;
	if (keysym == 97)
		data->shift_x -= 10;
	if (keysym == 100)
		data->shift_x += 10;
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	in_img(data);
}

void	ft_short(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	in_img(data);
}

int	handle_input(int keysym, t_fdf *data)
{
	printf("%d\n", keysym);
	if (keysym == 119 || keysym == 115 || keysym == 97 || keysym == 100)
		the_key(keysym, data);
	if (keysym == 65431)
	{
		change_tab(data, 1);
		ft_short(data);
	}
	if (keysym == 65433)
	{
		change_tab(data, 0);
		ft_short(data);
	}
	if (keysym == 65362)
	{
		data->zoom += 1;
		ft_short(data);
	}
	if (keysym == 65364)
	{
		data->zoom -= 1;
		ft_short(data);
	}
	if (keysym == 65307)
		ft_close(data);
	return (0);
}
