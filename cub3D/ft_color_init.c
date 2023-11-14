/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:49 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 13:59:11 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
		return (1);
	return (0);
}

void	get_c_color(t_cub3D *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->texture.c_color[0]);
	g = ft_atoi(data->texture.c_color[1]);
	b = ft_atoi(data->texture.c_color[2]);
	if (check_colors(r, g, b) == 0)
	{
		data->c_color = r;
		data->c_color = (data->c_color << 8) + g;
		data->c_color = (data->c_color << 8) + b;
	}
	else
	{
		printf("ERROR: CELING COLOR\n");
		the_ultimate_free(data);
	}
}

void	ft_color_init(t_cub3D *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->texture.f_color[0]);
	g = ft_atoi(data->texture.f_color[1]);
	b = ft_atoi(data->texture.f_color[2]);
	if (check_colors(r, g, b) == 0)
	{
		data->f_color = r;
		data->f_color = (data->f_color << 8) + g;
		data->f_color = (data->f_color << 8) + b;
	}
	else
	{
		printf("ERROR: FLORE COLOR\n");
		the_ultimate_free(data);
	}
	get_c_color(data);
}
