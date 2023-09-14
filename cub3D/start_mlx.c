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

int handel_input(int key, t_cub3D *data)
{
	if (key == 119)
		move_forward(data);
	if (key == 115)
		move_backward(data);
	if (key == 97)
		move_left(data);
	if (key == 100)
		move_right(data);
	if (key == 65363)
		rotate_right(data->player);
	if (key == 65361)
		rotate_left(data->player);
	if (key == 65307)
		ft_close(data);
	return (0);
}


int	handel_no_even(void *data)
{
	(void)data;
	return (0);
}

int		have_a_toure(t_cub3D *data)
{
	//key_handel(game);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	ft_raycasting(data);
	return (0);
}

int	start_mlx(t_cub3D *data)
{
	init_function(data);
	if (data->save == 1)
		ft_raycasting(data);
	mlx_hook(data->mlx.win_ptr, 17, 0L, &ft_close, data);
	mlx_key_hook(data->mlx.win_ptr, &handel_input, data);
	mlx_loop_hook(data->mlx.mlx_ptr, &have_a_toure, data);
	mlx_loop(data->mlx.mlx_ptr);
	return (0);
}
