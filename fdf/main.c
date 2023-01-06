/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:25 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:45:26 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dis(int **tab,char *file)
{
	int x;
	int j;
	int i;
	int y;
	
	j = 0;
	i = 0;
	x = size_x(file);
	y = size_y(file);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void one_time (t_fdf *data)
{
	data->zoom = 20;
	data->shift_x = 150;
	data->shift_y = 150;
}

int	main(int argc, char **argv)
{
	int fd;
	t_fdf data;

	if (argc == 1)
		return 0;
	if (argc == 3)
		return 0;
	data.file = argv[1];
	fd = open(data.file,O_RDONLY);
	malloc_map(&data);
	to_tab(fd, &data);
	close(fd);
	repair(&data);
	one_time(&data);
//	change_tab(&data,1);
	//dis(data.tab,data.file);
	//dis(tab.tab,data.file);
	open_win(&data);
	return 0;
}
