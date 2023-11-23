/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:49 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/23 10:00:53 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_postion_utils(t_cub3D *data)
{
	if (data->player->dir == 'W')
	{
		data->player->dir_y = 0.;
		data->player->dir_x = -1.;
		data->player->plan_y = -0.66;
		data->player->plan_x = 0.;
	}
	else
	{
		data->player->dir_x = 1.;
		data->player->dir_y = 0.;
		data->player->plan_y = 0.66;
		data->player->plan_x = 0.;
	}
}

void	set_postion(t_cub3D *data)
{
	if (data->player->dir == 'N' || data->player->dir == 'S')
	{
		data->player->dir_x = 0;
		if (data->player->dir == 'N')
		{
			data->player->dir_y = -1;
			data->player->plan_y = 0.;
			data->player->plan_x = 0.66;
		}
		else
		{
			data->player->dir_y = 1;
			data->player->plan_x = -0.66;
			data->player->plan_y = 0.;
		}
	}
	else if (data->player->dir == 'W' || data->player->dir == 'E')
		set_postion_utils(data);
}

void	set_position_init(t_cub3D *data, float x, float y)
{
	data->player->pos_x += x;
	data->player->pos_y += y;
}

void	get_pos_player(t_cub3D *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->map.map[++i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N'
				|| data->map.map[i][j] == 'E'
				|| data->map.map[i][j] == 'W'
				|| data->map.map[i][j] == 'S')
			{
				set_position_init(data, (float)j, (float)i);
				data->player->dir = data->map.map[i][j];
				data->map.map[i][j] = '0';
			}
			j++;
		}
	}
	set_postion(data);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		printf("ERROR: PLAYER MALLOC FAILER\n");
		exit(1);
	}
	player->pos_x = 0.5;
	player->pos_y = 0.5;
	player->dir_x = 0.;
	player->dir_y = 0.;
	player->mov_speed = 0.090;
	player->rot_speed = 0.070;
	player->plan_x = 0.;
	player->plan_y = 0.;
	player->dir = '0';
	return (player);
}
