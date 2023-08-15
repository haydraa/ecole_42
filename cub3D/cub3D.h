#ifndef	CUB3D_h
#define CUB3D_h

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_player
{
	double	x;
	double	y;
	char	dir;//direction
	double	planeX;
	double	planeY;
	double	dirX;
	double	dirY;
	double	time;
	double	oldtime;
	double	angle;
} t_player;

typedef struct s_cub3D
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**tab;
	int		fd;
	t_player player;
	int		bpp;
	int		e;
	void	*img;
	char	*addr;
	int		ll;
	int		y_map;
	char	**map;
}	t_cub3D;

char    *get_next_line(int fd);
//----------map_parssing_and_player-------------
void	get_map(t_cub3D *data, char ** argv);
int count_y(char **argv);
int get_pos_player(t_cub3D *data);
//---------start_mlx----------
int	start_mlx(t_cub3D *data);
void	cub_free(t_cub3D *data);
void	init_function(t_cub3D *data);



#endif
