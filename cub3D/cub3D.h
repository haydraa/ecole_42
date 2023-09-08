#ifndef	CUB3D_h
#define CUB3D_h

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>

#define WIDTH 1000
#define HIEGHT 1000

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	char	dir;//direction
	double	plan_x;
	double	plan_y;
	double	dir_x;
	double	dir_y;
	double	mov_speed;
	double	rot_speed;
}		t_player;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char 	*east;
	char	**f_color;
	char	**c_color;
	int		index;
}			t_texture;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	char	*path;
	int	bpp;
	int size_line;
	int endian;
	int width;
	int	height;
}		t_image;


typedef struct s_minilibix
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		bpp;
	int		e;
	void	*img;
	char	*addr;
	int		ll;
}			t_minilibix;	

typedef struct s_map
{
	int		**map_int;
	int		y_map;
	char	*line;
	char	**map;
}	t_map;

typedef struct s_sprite
{
	int x;
	int y;
}		t_sprite;

typedef struct	s_sprites
{
	t_sprite	*sprite;
	double		distance;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					text_x;
	int					text_y;
	int					x;
	int					y;
	struct s_sprites	*next;
}		t_sprites;

typedef struct s_raycast
{
	int x;
	int y;
	double camera_x;
	double prep_wall_dist;
	double ray_dir_x;
	double ray_dir_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double wall_x;
	double *z_buffer;
	int	map_x;
	int map_y;
	int step_x;
	int step_y;
	int hit;
	int side;
	int line_height;
	int draw_start;
	int draw_end;
	int text_x;
	int text_y;
}	t_raycast;

typedef struct s_cub3D
{
	int			fd;
	int			fd2;
	int			save;
	int			f_color;
	int 		c_color;
	int			index;
	t_player	*player;
	t_texture	texture;
	t_image		*image;
	t_sprites	*sprites_head;
	t_minilibix	mlx;
	t_image		*north;
	t_image		*south;
	t_image		*west;
	t_image		*east;
	t_raycast	raycast;
	t_map		map;
}				t_cub3D;

char	*get_next_line(int fd);
//----------map_parssing_and_player-------------
int		get_map(t_cub3D *data, char ** argv);
int		get_map_texture(t_cub3D *data, char **argv);
int		count_y(char **argv);
void		get_pos_player(t_cub3D *data);
int		line_check(char *line);
t_player    *init_player(void);
t_image *image_init(void);
void    texture_init(t_cub3D *data);
//---------start_mlx----------
int		start_mlx(t_cub3D *data);
void    mlx_put(t_image *image, int x, int y, int color);
void	cub_free(t_cub3D *data);
void	init_function(t_cub3D *data);
//----------utils-------
void	free_tab(char **tab);
void	ft_error(char *error, t_cub3D *data); 
//----------raycast----------
void    ft_raycasting(t_cub3D *data);
void    draw_col(t_cub3D *data);
void    ft_dda(t_cub3D *data);
void    ft_color_init(t_cub3D *data);


#endif
