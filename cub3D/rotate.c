/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:19 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:00:20 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_player *p)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = p->dir_x;
	p->dir_x = cos(-(p->rot_speed)) * p->dir_x
		- sin(-(p->rot_speed)) * p->dir_y;
	p->dir_y = sin(-(p->rot_speed)) * old_dir_x
		+ cos((-(p->rot_speed))) * p->dir_y;
	old_plan_x = p->plan_x;
	p->plan_x = cos(-(p->rot_speed)) * p->plan_x
		- sin(-(p->rot_speed)) * p->plan_y;
	p->plan_y = sin(-(p->rot_speed)) * old_plan_x
		+ cos((-(p->rot_speed))) * p->plan_y;
}

void	rotate_right(t_player *p)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = p->dir_x;
	p->dir_x = cos(p->rot_speed) * p->dir_x
		- sin(p->rot_speed) * p->dir_y;
	p->dir_y = sin(p->rot_speed) * old_dir_x
		+ cos(p->rot_speed) * p->dir_y;
	old_plan_x = p->plan_x;
	p->plan_x = cos(p->rot_speed) * p->plan_x
		- sin(p->rot_speed) * p->plan_y;
	p->plan_y = sin(p->rot_speed) * old_plan_x
		+ cos(p->rot_speed) * p->plan_y;
}
