/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:10 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:00:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_cub3D *data)
{
	if (key == 119)
		data->keys.key_w = 1;
	else if (key == 115)
		data->keys.key_s = 1;
	else if (key == 97)
		data->keys.key_d = 1;
	else if (key == 100)
		data->keys.key_a = 1;
	else if (key == 65307)
		data->keys.key_esc = 1;
	else if (key == 65361)
		data->keys.left_arr = 1;
	else if (key == 65363)
		data->keys.right_arr = 1;
	return (0);
}

int	key_release(int key, t_cub3D *data)
{
	if (key == 119)
		data->keys.key_w = 0;
	else if (key == 115)
		data->keys.key_s = 0;
	else if (key == 97)
		data->keys.key_d = 0;
	else if (key == 100)
		data->keys.key_a = 0;
	else if (key == 65307)
		data->keys.key_esc = 0;
	else if (key == 65361)
		data->keys.left_arr = 0;
	else if (key == 65363)
		data->keys.right_arr = 0;
	return (0);
}
