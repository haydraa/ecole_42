#include "cub3D.h"

int	ft_close(t_cub3D *data)
{
	mlx_destroy_window(data->dmlx.mlx_ptr, data->dmlx.win_ptr);
	mlx_destroy_display(data->dmlx.mlx_ptr);
	cub_free(data);
	free(data->dmlx.mlx_ptr);
	exit(0);
	return (0);
}

void	mlx_put(t_cub3D *data, int x, int y, int color)
{
	char *dst;

	if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->dmlx.addr + (y * data->dmlx.ll + x * (data->dmlx.bpp / 8));
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


int	start_mlx(t_cub3D *data)
{
	init_function(data);
	data->dmlx.mlx_ptr = mlx_init();
	if (data->dmlx.mlx_ptr == NULL)
		return (1);
	data->dmlx.win_ptr = mlx_new_window(data->dmlx.mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (data->dmlx.win_ptr == NULL)
		return (1);
	if (data->save == 1)
		ft_raycasting(data);
	mlx_hook(data->dmlx.win_ptr, 17, 0L, &ft_close, data);
	mlx_key_hook(data->dmlx.win_ptr, &handel_input, data);
	mlx_loop_hook(data->dmlx.mlx_ptr, &handel_no_even, data);
	mlx_loop(data->dmlx.mlx_ptr);
	return (0);
}
