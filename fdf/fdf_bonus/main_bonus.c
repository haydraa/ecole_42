/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:25 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/11 18:08:08 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	line_split(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ' ')
		{
			if (line[i + 1] == ' ')
				i++;
			j++;
		}
		i++;
	}
	return (j);
}

void	one_time(t_fdf *data)
{
	data->zoom = 20;
	data->shift_x = 150;
	data->shift_y = 150;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	data;

	if (argc != 2)
		return (0);
	data.file = argv[1];
	fd = open(data.file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error_map\n", 10);
		return (0);
	}
	malloc_map(&data);
	to_tab(fd, &data);
	close(fd);
	repair(&data);
	one_time(&data);
	change_tab(&data, 1);
	open_win(&data);
	return (0);
}
