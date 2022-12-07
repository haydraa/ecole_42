#include "fdf.h"

/*void img_pix_put(t_img *img,int x,int y,int color)
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
	*(unsigned int*)dst = color;
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
}*/

int size_x(char *file)
{
	int x;
	char *line;
	int fd;
	int i;

	i = 0;
	fd = open(file,O_RDONLY);
	x = 0;
	line = get_next_line(fd);
	while (line[i] != '\n')
	{
		if (ft_isdigit(line[i]) == 1)
				x++;
		i++;
	}
	close(fd);
	free(line);
	return x;
}

int size_y(char *file)
{
	int y;
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	y = 0;
	while (line)
	{
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return y;
}
char  **ft_map(int fd,char *file)
{
	int x;
	int y;
	int j;
	char  **map;
	static char *line;
	int i;

	i = 0;
	j = 0;
	y = size_y(file);
	x = size_x(file);
	while (line)
	{
		line = get_next_line(fd);
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 0)
				map[j][i] = (line[i]);
			i++;
		}
		j++;
	}
	return map;
}

int	main(int argc, char **argv)
{
	int fd;
	int x, y;

	x = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	char **map;
	map = ft_map(fd,argv[1]);
	while (map[y][x])
	{
		while (map[y][x])
		{
			ft_printf("%c",map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	close(fd);
	return 0;
}
