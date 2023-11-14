/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:15 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:05:49 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_cub3D *data)
{
	if (data->map.map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			+ data->player->dir_x * data->player->mov_speed)] == '0')
		set_position_init(data, data->player->dir_x
			* data->player->mov_speed, 0);
	if (data->map.map[(int)(data->player->pos_y + data->player->dir_y
			* data->player->mov_speed)][(int)(data->player->pos_x)] == '0')
		set_position_init(data, 0, data->player->dir_y
			* data->player->mov_speed);
}

void	move_backward(t_cub3D *data)
{
	if (data->map.map[(int)(data->player->pos_y)]
		[(int)(data->player->pos_x - data->player->dir_x
		* data->player->mov_speed)] == '0')
		set_position_init(data, -(data->player->dir_x
				* data->player->mov_speed), 0);
	if (data->map.map[(int)(data->player->pos_y - data->player->dir_y
			* data->player->mov_speed)][(int)(data->player->pos_x)] == '0')
		set_position_init(data, 0, -(data->player->dir_y
				* data->player->mov_speed));
}

void	move_right(t_cub3D *data)
{
	if (data->map.map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			+ data->player->plan_x * data->player->mov_speed)] != '1')
		data->player->pos_x = data->player->pos_x + data->player->plan_x
			* data->player->mov_speed;
	if (data->map.map[(int)(data->player->pos_y + data->player->plan_y
			* data->player->mov_speed)]
		[(int)(data->player->pos_x)] != '1')
		data->player->pos_y = data->player->pos_y + data->player->plan_y
			* data->player->mov_speed;
}

void	move_left(t_cub3D *data)
{
	if (data->map.map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			- data->player->plan_x * data->player->mov_speed)] != '1')
		data->player->pos_x = data->player->pos_x - data->player->plan_x
			* data->player->mov_speed;
	if (data->map.map[(int)(data->player->pos_y - data->player->plan_y
			* data->player->mov_speed)]
		[(int)(data->player->pos_x)] != '1')
		data->player->pos_y = data->player->pos_y - data->player->plan_y
			* data->player->mov_speed;
}
