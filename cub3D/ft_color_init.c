#include "cub3D.h"

int	check_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
			return (1);
	return (0);
}

void	get_c_color(t_cub3D *data)
{
	int r;
	int g;
	int b;
	
	r = ft_atoi(data->texture.c_color[0]);
	g = ft_atoi(data->texture.c_color[1]);
	b = ft_atoi(data->texture.c_color[2]);
	if (check_colors(r, g, b) == 0)
	{
		data->c_color = r;
		data->c_color = (data->c_color << 8) + g;
		data->c_color = (data->c_color << 8) + b;

	}
	else
	{
		printf("Error_celing_color\n");
		//free;
		exit(1);
	}

}

void	ft_color_init(t_cub3D *data)
{
	int r;
	int g;
	int b;
	
	r = ft_atoi(data->texture.f_color[0]);
	g = ft_atoi(data->texture.f_color[1]);
	b = ft_atoi(data->texture.f_color[2]);
	if (check_colors(r, g, b) == 0)
	{
		data->f_color = r;
		data->f_color = (data->f_color << 8) + g;
		data->f_color = (data->f_color << 8) + b;

	}
	else
	{
		printf("Error_flore_color\n");
		//free;
		exit(1);
	}
	get_c_color(data);
}
