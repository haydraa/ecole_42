#include "fdf.h"


int  x_fla(float x,float y,float z)
{
	float x_cart;
	float x1;

	x_cart = (x-z)*cos(0.46365);
	x1 = x_cart - x;
	return (x1);
}

int  y_fla(float x, float y,float z)
{
	float y_cart;
	float y1;
	
	y1 = y;
	y_cart = y + (x + z) * sin(0.46365);
	y1 = -y_cart + y;
	return (y1);
}

void in_img(void *mlx_ptr,void *win_ptr,char *file, int **tab)
{
	t_data img;
	t_dda dda;

	int i = 0;
	int j;
	int y = size_y(file);
	int x = size_x(file);
	img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (j != y - 1)
				ft_dda(img,(float)i, (float)j, (float)i, (float)(j+1),tab);
			if (i != x - 1)
				ft_dda(img,(float)i,(float)j, (float)(i+1), (float)j,tab);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_ptr,win_ptr,img.img,100,100);
}

void isometric(float  *x,float *y,int  z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

/*void ft_dda(t_data img, float x0, float y0, float x1 ,float y1, int **tab)
{
	t_dda dda;
	int i;
	int steps;
	int z;
	int z1;
	
	int a,a1,b,b1;
	dda.zoom = 20;
	z = tab[(int)y0][(int)x0];
	z1 = tab[(int)y1][(int)x1];
	x0 *= dda.zoom;
	x1 *= dda.zoom;
	y0 *= dda.zoom;
	y1 *= dda.zoom;
	dda.color = (z) ? 0xe80c0c : 0xFFFFFF;
	dda.dx = x1 - x0;
	dda.dy = y1 - y0;
	isometric(&x0, &y0,z);
	isometric(&x1, &y1,z1);
	ft_printf("%d  %d\n", x1,y1);	
	if (abs(dda.dx) > abs(dda.dy))
		steps = abs(dda.dx);
	else
		steps = abs(dda.dy);
	dda.xinc = (float)dda.dx / steps;
	dda.yinc = (float)dda.dy / steps;
	dda.X = x0;
	dda.Y = y0;

	i = 0;
	while (i <= steps)
	{
		mlx_put(&img,dda.X, dda.Y, dda.color);
		dda.X += dda.xinc;
		dda.Y += dda.yinc;
		i++;
	}
}*/

#define MAX1(a ,b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)
float	mod(float i)
{
	return ((i < 0) ? -i : i;
}
void bransh(t_data img,float x,float y, float x1, float y1, int **tab)
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(NOD(x_step),MOD(y_step))
	x_step /= max;
	y_step /= max;
	while ((int)x - x1 || (int)(y - y1))
	{
		mlx_put(&img, x, y,0xFFFFFF);
		x += x_step;
		y += y_step;
	}
}
void open_win(char *file ,int **tab)
{
	t_mlx mlx;

	mlx.ptr = mlx_init();
	if(mlx.ptr == NULL)
		return ;

	mlx.win_ptr = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (mlx.win_ptr == NULL)
	{
		free(mlx.win_ptr);
		return ;
	}
	in_img(mlx.ptr, mlx.win_ptr, file,tab);
	mlx_loop_hook(mlx.ptr,&handle_no_even,&mlx);
	mlx_key_hook(mlx.win_ptr,&handle_input,&mlx);
	mlx_loop(mlx.ptr);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
}

void	mlx_put(t_data *data, int x, int y, int color)
{
	char *dst;


	dst = data->addr+(y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}
