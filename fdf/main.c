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
int handle_no_even(void *data)
{
	return(0);
}

int handle_input(int keysym,t_mlx *mlx)
{
//		ft_printf("%d",keysym);

	if (keysym == 65307)
		mlx_destroy_window(mlx->ptr,mlx->win_ptr);
	return 0;
}

int	main(int argc, char **argv)
{
	int fd;
	t_tab tab;
	if (argc == 1)
		return 0;
	if (argc == 3)
		return 0;
	fd = open(argv[1],O_RDONLY);
	tab.tab = malloc_map(argv[1]);
	to_tab(fd, tab, argv[1]);
	close(fd);
	open_win(argv[1], tab.tab);
	return 0;
}
