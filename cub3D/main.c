/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/28 17:22:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_display(char **tab1)
{
	int i;

	i = -1;
	while (tab1[++i])
	{
		printf("%s", tab1[i]);
		printf("\n");
	}
}

int check_all(t_cub3D *data)
{
	int ret;
	int ret2;

	check_exist(data);
	ret = check_map(data->map.map);
	ret2 = check_map2(data->map.map);
	if (ret == -1 || ret2 == -1)
		printf("ERROR: MAP IS NOT COLOSE\n");
	else if (ret == -2)
		printf("ERROR: ERROR INSIDE THE MAP\n");
	else if (ret == -3)
		printf("ERROR: ERROR WITH DIRECTION OF PLAYER\n");
	if (ret < 0 || ret2 < 0)
		the_ultimate_free(data);
	check_colors2(data);
	check_xpm(data->texture.north, data);
	check_xpm(data->texture.south, data);
	check_xpm(data->texture.west, data);
	check_xpm(data->texture.east, data);
	return (0);
}

void open_and_read_map(t_cub3D *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		printf("ERROR: INVALID FILE\n");
		exit(0);
	}
	null_init(data);
	if (get_all(data) == 1)
		return;
	if (check_all(data) == -1)
		return;
	ft_color_init(data);
	data->player = init_player();
	texture_init(data);
	get_pos_player(data);
	start_mlx(data);
}

int main(int argc, char **argv)
{
	t_cub3D data;

	if (argc < 2 || argc > 2)
	{
		printf("ERROR: ARGUMENT!\n");
		exit(1);
	}
	else
	{
		check_cub(argv[1]);
		open_and_read_map(&data, argv);
	}
	return (0);
}
