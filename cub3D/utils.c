/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:32 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:00:33 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

bool	stupid_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (true);
	return (false);
}

void	free_image(t_cub3D *data, t_image *image)
{
	if (image->path != NULL)
		free(image->path);
	if (image->img_ptr != NULL)
		mlx_destroy_image(data->mlx.mlx_ptr, image->img_ptr);
	free(image);
}

int	identifcation(t_cub3D *data, char **tmp)
{
	if (ft_strcmp(tmp[0], "NO") == 0)
		data->texture.north = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		data->texture.south = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		data->texture.west = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		data->texture.east = ft_strdup(tmp[1]);
	else
		return (-1);
	return (0);
}
