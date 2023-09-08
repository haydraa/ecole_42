#include "cub3D.h"

int	ft_close(t_cub3D *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_display(data->mlx.mlx_ptr);
	cub_free(data);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}

void	mlx_put(t_image *image, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	image->img_data[y * image->size_line + x * image->bpp / 8] = r;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 1] = g;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 2] = b;
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
	if (data->save == 1)
		ft_raycasting(data);
	mlx_hook(data->mlx.win_ptr, 17, 0L, &ft_close, data);
	mlx_key_hook(data->mlx.win_ptr, &handel_input, data);
	mlx_loop_hook(data->mlx.mlx_ptr, &handel_no_even, data);
	mlx_loop(data->mlx.mlx_ptr);
	return (0);
}
