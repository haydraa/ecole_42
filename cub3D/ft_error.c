#include "cub3D.h"

void	ft_error(char *error, t_cub3D *data)
{
	(void)data;
		printf("%s\n", error);
	//free map;
	//free map_int;
	exit(1);
}
