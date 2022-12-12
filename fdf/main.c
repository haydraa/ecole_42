#include "fdf.h"
#include <math.h>
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

int ft_abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	mlx_put(t_data *data, int x, int y, int color)
{
	char *dst;
	
	
	dst = data->addr+(y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
/*	while (i >= 0)
	{
		if (data->endian != 0)
			*dst++ = color;
		else 
			*dst++ = (color >> (data->bpp - 8 -i)) & 0xFF;
		i -= 8;
	}*/
}

void ft_dda(t_data img, int x0, int y0, int x1 ,int y1)
{	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	float   
	xinc = (float)dx / steps;
	float 
	yinc = (float)dy / steps;
	float X = x0;
	float Y = y0;
	
	int i = 0;
	while (i <= steps)
	{
		mlx_put(&img,X , Y,0x00FF0000);
		X += xinc;
		Y += yinc;
		i++;
	}
	
}

void in_img(void *mlx_ptr, void *win_ptr,int **tab)
{
	t_data img;
	int i = 0;
	int j;
	int y = size_y("fdf.fdf");
	int x = size_x("fdf.fdf");
	img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (j != y - 1)
				ft_dda(img,i * 32,j*32,i*32 ,(j+1)*32);
			if (i != x - 1)
				ft_dda(img, i * 32, j * 32, (i + 1) * 32, j * 32);
			j++;
		}	
		i++;
	}
	mlx_put_image_to_window(mlx_ptr,win_ptr,img.img,100,100);
}

int handle_no_even(void *data)
{
	return(0);
}

int handle_input(int keysym,t_vars *vars)
{
		ft_printf("%d",keysym);

	//if (keysym == 65307)
	//	mlx_destroy_window(vars->mlx_ptr,vars->win_ptr);
	return 0;
}

void open_win(int **tab)
{	
	t_vars vars;
	
	vars.mlx_ptr = mlx_init();
	if(vars.mlx_ptr == NULL)
		return ;
	
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (vars.win_ptr == NULL)
	{
		free(vars.win_ptr);
		return ;
	}
	in_img(vars.mlx_ptr, vars.win_ptr, tab);
	mlx_loop_hook(vars.mlx_ptr,&handle_no_even,&vars);
	mlx_key_hook(vars.win_ptr,&handle_input,&vars);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
}

int	main(int argc, char **argv)
{
	int fd;
	int **tab;

	fd = open(argv[1],O_RDONLY);
	tab = malloc_map(argv[1]);
	to_tab(fd, tab, argv[1]);
	close(fd);
	open_win(tab);
	return 0;
}
