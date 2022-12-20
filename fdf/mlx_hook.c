#include "fdf.h"

int handle_no_even(void *data)
{
	return(0);
}



int handle_input(int keysym,t_fdf *data)
{
//	ft_printf("%d\n",keysym);
	if (keysym == 119)
			data->shift_y -= 10;
	if (keysym == 115)
			data->shift_y += 10;
	if (keysym == 97)
			data->shift_x -= 10;
	if (keysym == 100) 
			data->shift_x += 10;
	if (keysym == 65362) 
	{
		data->zoom += 1;
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		in_img(data);
	}
	if (keysym == 65431)
		change_tab(data,1);
	if (keysym == 65433)
		change_tab(data,0);
	if (keysym == 65364) 
	{
		data->zoom -= 1;
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		in_img(data);
	}
	mlx_clear_window(data->mlx_ptr,data->win_ptr);
	in_img(data);
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		the_free(data);
	}
	return 0;
}
