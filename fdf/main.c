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

int find_len_y(char *argv)
{
	int fd;
	char *line;
	int i;
	int j;
	char **map;
	i = 0;
	j = 0;
	fd = open(argv,O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return i;
}
int find_len_x(char *argv)
{	
	int fd;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(argv,O_RDONLY);
	line = get_next_line(fd);
	while (line[i])
	{
		if (ft_isdigit(line[i] == 0))
			j++;
		i++;
	}
	close(fd);
	return j;
}

char **ft_creat_tab(char *argv)
{
	int	x;
	int y;
	char **map;
	
	x = find_len_x(argv);
	y = find_len_y(argv);
	map = malloc(sizeof(char **) * y);
	while (y >= 0)
	{
		map[y] = ft_calloc(sizeof(char *), x);
		y--;
	}
	return (map);
}

void ft_get_next_line(char *argv , char **tab)
{
	int  fd;
	char *line;
	int i;
	int x;
	int y;
	
	y = 0;
	fd = open(argv,O_RDONLY);
	while (line != NULL )
	{
		i = 0;
		x = 0;
		line = get_next_line(fd);
		while (line[i])
		{
			if(ft_isdigit(line[i]) == 0)
				i++;
			tab[y][x] = line[i];
			i++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	char **map;
	int x;
	x = 0;
	if (argc > 2)
		return 0;
	map = ft_creat_tab(argv[1]);
	ft_get_next_line(argv[1], map);
	while (map[x])
	{
		ft_printf("%s", map[x]);
		x++;
	}
	return 0;
}
