# include "cub3D.h"

void    null_init(t_cub3D *data)
{
    data->texture.c_color = NULL;
	data->texture.f_color = NULL;
    data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.east = NULL;    
}

void    last_check(t_cub3D *data)
{
    data->texture.c_color = NULL;
	data->texture.f_color = NULL;
    data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.east = NULL;
    
}