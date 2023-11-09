#include "cub3D.h"

void	ft_display(char **tab1)
{
	int i = -1;
	while (tab1[++i])
	{
		printf("%s", tab1[i]);
		printf("\n");
	}
}

int	check_map(char **map)
{
	int i;
	int j;
	int dir_player;
	int len = 0;

	while (map[len])
		len++;
	dir_player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == len - 1)
			{
				if (map[i][j] != '1')
					return (-1);
			}
			else if (i != 0)
			{
				if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
					return (-1);
				else if (map[i][j] != '1' && map[i][j] != '2'
					 && map[i][j] != '0' && map[i][j] != 'N'
					 && map[i][j] != 'E' && map[i][j] != 'S'
					 && map[i][j] != 'W')
					return (-2);
				if (map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W'|| map[i][j] == 'N')
					dir_player++;
			}
			j++;
		}
		i++;
	}
	if (dir_player < 1 || dir_player > 1)
		return (-3);
	return (0);
}

int check_map2(char **map)
{
	int i;
	int j;
	int len;
	int len2;

	i = 0;
	while (map[i])
	{
		if (map[i + 1] != NULL)
		{
			j = 0;
			len = ft_strlen(map[i]);
			len2 = ft_strlen(map[i + 1]);
			if (len != len2)
			{
				if (len < len2)
				{
					while (j < len2)
					{
						if (j >= len)
						{
							if (map[i + 1][j] != '1')
								return (-1);
						}
						j++;
					}
				}
				else if (len > len2 && i != 0)
				{
					while (j < len)
					{
						if (j >= len)
						{
							if (map[i][j] != '1')
								return (-1);
						}
						j++;
					}
				}
			}
		}
		i++;
	}
	return (0);
}

int	check_all(t_cub3D *data)
{
	int ret;
	int ret2;

	check_exist(data);
	ret = check_map(data->map.map);
	ret2 = check_map2(data->map.map);
	if (ret == -1 || ret2 == -1)
	{
		printf("ERROR: MAP IS NOT COLOSE\n");
		the_ultimate_free(data);
	}
	else if (ret == -2) 
	{
		printf("ERROR: ERROR INSIDE THE MAP\n");
		the_ultimate_free(data);
	}
	else if (ret == -3)
	{
		printf("ERROR: ERROR WITH DIRECTION OF PLAYER\n");
		the_ultimate_free(data);
	}
	check_colors2(data);
	check_xpm(data->texture.north, data);
	check_xpm(data->texture.south, data);
	check_xpm(data->texture.west, data);
	check_xpm(data->texture.east, data);
	return (0);

}


void	open_and_read_map(t_cub3D *data, char **argv)
{
	null_init(data);
	if (get_all(data, argv) == 1)
		return;
	if (check_all(data) == -1)
		return;
	data->player = init_player();
	data->image = image_init();
//	data->save = 1;
//	ft_display(data->map.map);
	texture_init(data);
	get_pos_player(data);
	if (start_mlx(data) == 1)
		cub_free(data);
}

int main(int argc, char **argv)
{
	t_cub3D	data;

	if (argc < 2 || argc > 2)
	{
		printf("Error argument!\n");
		exit(1);
	}
	else
	{
		check_cub(argv[1]);
		open_and_read_map(&data, argv);
	}
	return (0);
}
