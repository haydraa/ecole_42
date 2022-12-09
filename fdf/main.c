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
	char **num;
	int fd;
	int i;

	x = 0;
	i = 0;
	fd = open(file,O_RDONLY);
	line = get_next_line(fd);
	num = ft_split(line, ' ');
	while (num[i])
	{	
		i++;
	}

	close(fd);
	free(num);
	return i;
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


int **malloc_map(char *file)
{
	int y;
	int x;
	int j;
	int **tab;
	j = 0;
	y = size_y(file) - 1;
	x = size_x(file);
	tab = (int**)malloc(sizeof(int*) * y);
	while (j < y)
	{
		tab[j] = (int *)malloc(x * sizeof(int));
		j++;
	}
	return tab;
}

void fil_tab(int **tab, char *line)
{
	char **num;
	int i;

	i = 0;
	num = ft_split(line,' ');
	while (num[i])
	{
		i++;
	}
}

int	main(int argc, char **argv)
{
	int fd;
	int **tab;
	char *line;
	char **num;
	int y;
	int i;
	int x = 0;
	int j = 0;
	i = 0;
	y = size_y(argv[1]);
	fd = open(argv[1],O_RDONLY);
	tab = malloc_map(argv[1]);
	while (i < y)
	{
		line = get_next_line(fd);
		fil_tab(tab,line);
	}
	close(fd);
	return 0;
}
