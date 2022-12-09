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
void *in_img(void *mlx_ptr)
{
	
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
	while (1)
		;
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
