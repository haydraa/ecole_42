#include "cub3D.h"

int	get_pos_player(t_cub3D *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' 
				|| data->map.map[i][j] == 'E' 
				|| data->map.map[i][j] == 'W' 
				|| data->map.map[i][j] == 'S')
			{
				data->player.pos_x = i;
				data->player.pos_y = j;
				data->player.dir = data->map.map[i][j];
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
