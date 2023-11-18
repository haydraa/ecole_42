/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:10 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/18 14:08:01 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handel_key_event(int key, t_cub3D *data, int is_press)
{
	if (key == 119)
		data->keys.key_w = is_press;
	if (key == 115)
		data->keys.key_s = is_press;
	if (key == 97)
		data->keys.key_d = is_press;
	if (key == 100)
		data->keys.key_a = is_press;
	if (key == 65307)
		data->keys.key_esc = is_press;
	if (key == 65361)
		data->keys.left_arr = is_press;
	if (key == 65363)
		data->keys.right_arr = is_press;
	return (0);
	
}

int	key_press(int key, t_cub3D *data)
{
	handel_key_event(key, data, 1);
	return (0);
}

int	key_release(int key, t_cub3D *data)
{
	handel_key_event(key, data, 0);
	return (0);
}
