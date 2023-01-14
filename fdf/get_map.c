/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:01 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/06 16:25:53 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	size_x(char *file)
{
	int		x;
	char	*line;
	int		fd;
	int		i;
	int		j;

	x = 0;
	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		while (x < 1)
		{
			i = line_split(line);
			x++;
		}
		if (!line)
			break ;
		free(line);
	}
	free(line);
	close(fd);
	return (i + 1);
}

int	size_y(char *file)
{
	int		y;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}

void	malloc_map(t_fdf *data)
{
	int	j;

	j = 0;
	data->core_y = size_y(data->file);
	data->core_x = size_x(data->file);
	data->tab = (int **)ft_calloc(sizeof(int *), data->core_y);
	while (j < data->core_y)
	{
		data->tab[j] = (int *)ft_calloc(data->core_x, sizeof(int));
		j++;
	}
}

void	fil_tab(int *tab, char *line, int x)
{
	char	**num;
	int		i;
	int		j;

	j = 0;
	i = 0;
	num = ft_split(line, ' ');
	while (num[i] && i < x)
	{
		tab[i] = ft_atoi(num[i]);
		i++;
	}
	i = 0;
	while (num[i])
		i++;
	while (j < i)
	{
		free(num[j]);
		j++;
	}
	free(num);
}

void	to_tab(int fd, t_fdf *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fil_tab(data->tab[i], line, data->core_x);
		free(line);
		i++;
	}
}
