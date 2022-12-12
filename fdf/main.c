#include "fdf.h"

void dis(int **tab,char *file)
{
	int x;
	int j;
	int i;
	int y;
	
	j = 0;
	i = 0;
	x = size_x(file);
	y = size_y(file);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	mlx_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr+(y + data->line_len + x * (data->bpp/8));
	*(unsigned int*)dst = color;
}

void in_img(void *mlx_ptr, void *win_ptr)
{
	t_data img;
	int i = 0;
	int j = 0;

   img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,&img.endian);	
	while (j < WINDOW_WIDTH)
	{
		while (i < WINDOW_HEIGHT)
		{
			mlx_put(&img,i,j,0xFF0000);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(mlx_ptr,win_ptr,img.img,0,0);
	mlx_loop(mlx_ptr);
}
void open_win(void)
{	
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if(mlx_ptr == NULL)
		return ;
	
	win_ptr = mlx_new_window(mlx_ptr,WINDOW_WIDTH ,WINDOW_HEIGHT, "FDF");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return ;
	}
	in_img(mlx_ptr,win_ptr);
	mlx_destroy_window(mlx_ptr,win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

int	main(int argc, char **argv)
{
	int fd;
	int **tab;

	fd = open(argv[1],O_RDONLY);
	tab = malloc_map(argv[1]);
	to_tab(fd, tab, argv[1]);
	close(fd);
	open_win();
	return 0;
}
