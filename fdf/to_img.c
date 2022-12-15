#include "fdf.h"



void in_img(t_mlx *mlx,char *file, t_tab *tab)
{
	t_data img;
	t_dda dda;
	int i;
	int j;

	i = 0;
	img.img = mlx_new_image(mlx->ptr, WINDOW_WIDTH,WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < tab->core_x)
	{
		j = 0;
		while (j < tab->core_y)
		{
			if (j != tab->core_y - 1)
			{
				in_struct(&dda , i,j, 0);
				ft_dda(img,&dda, tab);
			}	
			if (i != tab->core_x - 1)
			{
				in_struct(&dda, i,j,1);
				ft_dda(img,&dda,tab);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr,mlx->win_ptr,img.img,0,0);
}

void ft_dda(t_data img, t_dda *dda, t_tab *tab)
{
	t_glob glob;

	glob.i = 0;
	color_rgb(dda,tab);
	zoom(dda);
	isometric(&dda->x0, &dda->y0,dda->z);
	isometric(&dda->x1, &dda->y1,dda->z1);
	get_place(dda);
	dda->dx = dda->x1 - dda->x0;
	dda->dy = dda->y1 - dda->y0;
	if (abs(dda->dx) > abs(dda->dy))
		glob.steps = abs(dda->dx);
	else
		glob.steps = abs(dda->dy);
	dda->xinc = (float)dda->dx / glob.steps;
	dda->yinc = (float)dda->dy / glob.steps;
	dda->X = dda->x0;
	dda->Y = dda->y0;	
	while (glob.i <= glob.steps)
	{
		mlx_put(&img,dda->X, dda->Y, dda->color);
		dda->X += dda->xinc;
		dda->Y += dda->yinc;
		glob.i++;
	}
}

void open_win(char *file ,t_tab *tab)
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
	in_img(&mlx, file, tab);
	mlx_loop_hook(mlx.ptr,&handle_no_even,&mlx);
	mlx_key_hook(mlx.win_ptr,&handle_input,&mlx);
	mlx_loop(mlx.ptr);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
}

void	mlx_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr+(y * data->line_length + x * (data->bits_per_pixel/8));
		*(unsigned int*)dst = color;
	}
}
