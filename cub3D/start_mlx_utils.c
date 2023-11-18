/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:23 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/18 15:08:30 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_function(t_cub3D *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!(data->mlx.mlx_ptr))
	{
		printf("mlx_ptr has a problem\n");
		exit(1);
	}
	fill_texturs(data);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			WIDTH, HIEGHT, "CUB3D");
	if (!(data->mlx.win_ptr))
	{
		printf("win_ptr has a problem\n");
		exit(1);
	}
	data->image->img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HIEGHT);
	data->image->img_data = mlx_get_data_addr(data->image->img_ptr,
			&(data->image->bpp), &(data->image->size_line),
			&(data->image->endian));
}
