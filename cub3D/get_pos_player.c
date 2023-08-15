#include "cub3D.h"

int	get_pos_player(t_cub3D *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' 
				|| data->map[i][j] == 'E' 
				|| data->map[i][j] == 'W' 
				|| data->map[i][j] == 'S')
			{
				data->player.x = i;
				data->player.y = j;
				data->player.dir = data->map[i][j];
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
