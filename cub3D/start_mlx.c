#include "cub3D.h"

int	ft_close(t_cub3D *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	cub_free(data);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	mlx_put(t_cub3D *data, int x, int y, int color)
{
	char *dst;

	if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int handel_input(int keysys, t_cub3D *data)
{
	if (keysys == 65307)
		ft_close(data);
	return (0);
}


int	handel_no_even(void *data)
{
	(void)data;
	return (0);
}

void	draw_rectangle(t_cub3D *data, int x, int y, int color)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x,y, color, "");
}

void	draw_map(t_cub3D *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			while (data->map[i][j] == ' ')
				j++;
			int tile = ft_atoi(&data->map[i][j]);
			int x = j*20;
			int y = i*20;
			int color = (tile == 1) ? 0x00FF0000:0x00FFFFFF;
			mlx_put(data, x, y, color);
			j++;
		}
		i++;
	}
}


int	draw(t_cub3D *data)
{
//	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->e);
	if (!data->img || !data->win_ptr)
		exit(0);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}


int	start_mlx(t_cub3D *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (data->win_ptr == NULL)
		return (1);
	draw(data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_close, data);
	mlx_key_hook(data->win_ptr, &handel_input, data);
	mlx_loop_hook(data->mlx_ptr, &handel_no_even, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
