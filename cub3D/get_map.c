/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:39 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:04:12 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	resize_tab(t_cub3D *data, char *line)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = NULL;
	while (data->map.map[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		the_ultimate_free(data);
	while (j < i)
	{
		tmp[j] = data->map.map[j];
		j++;
	}
	tmp[j++] = ft_strdup(line);
	tmp[j] = NULL;
	j = 0;
	free(data->map.tmp);
	data->map.tmp = NULL;
	free(data->map.map);
	data->map.map = tmp;
}

void	first_malloc(t_cub3D *data)
{
	data->map.map = (char **)malloc(sizeof(char *) * 2);
	if (!data->map.map)
		the_ultimate_free(data);
	data->map.map[0] = ft_strdup(data->map.tmp);
	data->map.map[1] = NULL;
	free(data->map.tmp);
}

int	get_map(t_cub3D *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	first_malloc(data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line_check(line, data) == 0)
			resize_tab(data, data->map.tmp);
		else
		{
			data->map.map_index++;
			free(line);
			break ;
		}
		free(line);
	}
	return (0);
}

int	get_all(t_cub3D *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		get_colors(data, line);
		texture_id(data, line);
		if (line_check(line, data) == 0)
		{
			if (data->map.map_index == 0)
				get_map(data, data->fd);
			else
			{
				free(data->map.tmp);
				data->map.tmp = NULL;
			}
		}
		free(line);
	}
	close(data->fd);
	return (0);
}
