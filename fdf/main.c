#include "fdf.h"

void img_pix_put(t_img *img,int x,int y,int color)
{
	char *pixel;
	int i;
	
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x *(img->bpp/ 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> i) & 0xFF;
		i -= -8;
	}
	//*(unsigned int*)dst = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;
	
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++,i,rect.color);
		++i;
	}
	return(0);
}

void render_backg(t_img *img,int color)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int render(t_data *data)
{
	if (data->win_ptr == NULL)
			return (1);
	render_backg(&data->img, 0xFF0000);
	render_rect(&data->img,(t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT- 100, 100, 100, 0x00FF00});
	render_rect(&data->img,(t_rect){0, 0,100,100,0xFF0000});
	mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img.mlx_img,0,0);
	return 0;
}
int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
/*	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}*/

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	//mlx_loop_hook(data.mlx_ptr, &render, &data);
//	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

/*int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,WINDOW_WIDTH,WINDOW_HEIGHT,"hello worls!");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr,WINDOW_WIDTH,WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.line_len , &data.img.endian);
	my_mlx_pixel_put(&img, 200, 200, 0xF0F000);
	mlx_put_image_to_window(data,win_ptr, mlx_img, 10, 10);
	mlx_loop(data.mlx_ptr);
	return 0;
}*/
