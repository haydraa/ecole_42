/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:53 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 13:59:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_wall_dist(t_cub3D *data)
{
	if (data->raycast.side_dist_x < data->raycast.side_dist_y)
	{
		data->raycast.side_dist_x += data->raycast.delta_dist_x;
		data->raycast.map_x += data->raycast.step_x;
		if (data->raycast.step_x == -1)
			data->raycast.side = 0;
		else
			data->raycast.side = 1;
	}
	else
	{
		data->raycast.side_dist_y += data->raycast.delta_dist_y;
		data->raycast.map_y += data->raycast.step_y;
		if (data->raycast.step_y == -1)
			data->raycast.side = 2;
		else
			data->raycast.side = 3;
	}
}

void	ft_dda(t_cub3D *data)
{
	while (data->raycast.hit != 1)
	{
		get_wall_dist(data);
		if (data->map.map[data->raycast.map_y][data->raycast.map_x] == '1')
			data->raycast.hit = 1;
	}
}
