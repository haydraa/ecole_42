/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:15 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:45:16 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(float  *x,float *y,int  z)
{
	*x = (*x - *y) * cos(ANGLE);
	*y = (*x + *y) * sin(ANGLE) - z;
}

void zoom(t_fdf *data)
{
	data->x0 *= data->zoom;
	data->x1 *= data->zoom;
	data->y0 *= data->zoom;
	data->y1 *= data->zoom;
}

void get_place(t_fdf *data)
{	
	data->x0 += data->shift_x;
	data->y0 += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
}

void color_rgb(t_fdf *data)
{
	data->z = data->tab[(int)data->y0][(int)data->x0];
	data->z1 = data->tab[(int)data->y1][(int)data->x1];
	data->color = (data->z || data->z1) ? 0xe80c0c : 0xFFFFFF;	
}

void in_struct(t_fdf *data, int  i,int  j, int index)
{
	if (index == 0)
	{
		data->x0 = i;
		data->y0 = j;
		data->x1 = i;
		data->y1 = j + 1;
	}
	if (index == 1)	
	{
		data->x0 = i;
		data->y0 = j;
		data->x1 = i + 1;
		data->y1 = j;
	}
}
