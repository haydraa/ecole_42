# include "cub3D.h"

void    null_init(t_cub3D *data)
{
    data->texture.c_color = NULL;
	data->texture.f_color = NULL;
    data->texture.north = NULL;
	data->map.map = NULL;
	data->map.map_index = 0;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.east = NULL;    
}

void    last_check(t_cub3D *data, int i)
{
	if (i == 1)
	{
		if (data->map.map == NULL)
		{
			printf("Missing Map");
			exit(1);
			//test;
		}
	}
	else if (data->texture.c_color == NULL ||  data->texture.f_color == NULL)
	{
		printf("Missing Colors\n");
		free_tab(data->map.map);
		//test
		exit(1);
	}
	else if (data->texture.north == NULL || data->texture.south == NULL
		|| data->texture.west == NULL || data->texture.east == NULL)
	{
		printf("Missing textur\n");
		free_tab(data->map.map);
		//test
		exit(1);
	}
}
