#include "cub3D.h"

void	init_function(t_cub3D *data)
{
	//find_dirction()
	data->player.dirX = -1;
	data->player.dirY = 0;
	data->player.planeX = 0;
	data->player.planeY = 0.66;
	data->player.time = 0;
	data->player.oldtime = 0;
}
