#include "cub3D.h"

void	null_init(t_cub3D *data)
{
	data->texture.c_color = NULL;
	data->texture.f_color = NULL;
	data->texture.north = NULL;
	data->keys.left_arr = 0;
	data->keys.right_arr = 0;
	data->keys.key_w = 0;
	data->map.index = 0;
	data->keys.key_s = 0;
	data->keys.key_d = 0;
	data->keys.key_a = 0;
	data->keys.key_esc = 0;
	data->map.map = NULL;
	data->map.tmp = NULL;
	data->map.map_index = 0;
	data->texture.south = NULL;
	data->texture.north = NULL;
	data->texture.west = NULL;
	data->texture.east = NULL;
}

void	the_ultimate_free(t_cub3D *data)
{
	if (data->map.tmp != NULL)
		free(data->map.tmp);
	if (data->map.map != NULL)
		free_tab(data->map.map);
	if (data->texture.c_color != NULL)
		free_tab(data->texture.c_color);
	if (data->texture.f_color != NULL)
		free_tab(data->texture.f_color);
	if (data->texture.north != NULL)
		free(data->texture.north);
	if (data->texture.south != NULL)
		free(data->texture.south);
	if (data->texture.east != NULL)
		free(data->texture.east);
	if (data->texture.west != NULL)
		free(data->texture.west);
	exit(1);
}

void	check_exist(t_cub3D *data)
{
	if (data->map.map == NULL)
	{
		printf("ERROR: MISSING MAP\n");
		the_ultimate_free(data);
	}
	else if (data->texture.c_color == NULL || data->texture.f_color == NULL)
	{
		printf("ERROR: MISSING COLORS\n");
		the_ultimate_free(data);
	}
	else if (data->texture.north == NULL || data->texture.south == NULL
		|| data->texture.west == NULL || data->texture.east == NULL)
	{
		printf("ERROR: MISSING TEXTURE\n");
		the_ultimate_free(data);
	}
}
