/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:32 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/28 17:12:55 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_image(t_cub3D *data, t_image *image)
{
	if (image->path != NULL)
		free(image->path);
	if (image->img_ptr != NULL)
		mlx_destroy_image(data->mlx.mlx_ptr, image->img_ptr);
	free(image);
}

void	continue_id(t_cub3D *data, char **tmp)
{
	if (ft_strcmp(tmp[0], "SO") == 0)
	{
		if (data->texture.south != NULL)
			free(data->texture.south);
		data->texture.south = ft_strdup(tmp[1]);
		data->texture.index++;
	}
	else if (ft_strcmp(tmp[0], "WE") == 0)
	{
		if (data->texture.west != NULL)
			free(data->texture.west);
		data->texture.west = ft_strdup(tmp[1]);
		data->texture.index++;
	}
	else if (ft_strcmp(tmp[0], "EA") == 0)
	{
		if (data->texture.east != NULL)
			free(data->texture.east);
		data->texture.east = ft_strdup(tmp[1]);
		data->texture.index++;
	}
}

int	identifcation(t_cub3D *data, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	if (i <= 1)
		return (-1);
	if (tmp[1] && tmp[1] != NULL)
	{
		if (ft_strcmp(tmp[0], "NO") == 0)
		{
			if (data->texture.north != NULL)
				free(data->texture.north);
			data->texture.north = ft_strdup(tmp[1]);
			data->texture.index++;
		}
		else
			continue_id(data, tmp);
	}
	else
		return (-1);
	return (0);
}

void	check_calcul(t_cub3D *data)
{
	if (data->raycast.y < 0)
		data->raycast.y = 0;
	if (data->raycast.text_y < 0)
		data->raycast.text_y = 0;
	if (data->raycast.text_x < 0)
		data->raycast.text_x = 0;
}
