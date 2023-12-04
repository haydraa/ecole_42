/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:44 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/23 12:46:09 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define WIDTH 900
# define HIEGHT 1080

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	char	dir;
	double	plan_x;
	double	plan_y;
	double	dir_x;
	double	dir_y;
	double	mov_speed;
	double	rot_speed;
}			t_player;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	**f_color;
	char	**c_color;
	int		index;
}			t_texture;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	char	*path;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_keys
{
	int	left_arr;
	int	right_arr;
	int	key_w;
	int	key_s;
	int	key_d;
	int	key_a;
	int	key_esc;
}		t_keys;

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
	int		map_index;
	int		map_space;
	int		index;
	char	*tmp;
	char	**map;
}			t_map;

typedef struct s_raycast
{
	int		x;
	int		y;
	double	camera_x;
	double	prep_wall_dist;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_x;
	double	*z_buffer;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
}			t_raycast;

typedef struct s_cub3D
{
	int			fd;
	int			f_color;
	int			c_color;
	int			index;
	t_keys		keys;
	t_player	*player;
	t_texture	texture;
	t_image		*image;
	t_minilibix	mlx;
	t_image		*north;
	t_image		*south;
	t_image		*west;
	t_image		*east;
	t_raycast	raycast;
	t_map		map;
}				t_cub3D;

char		*get_next_line(int fd);
//----------map_parssing_and_player-------------
int			get_all(t_cub3D *data);
int			get_map(t_cub3D *data, int fd);
int			texture_id(t_cub3D *data, char *line);
bool		stupid_check(char *str);
int			get_colors(t_cub3D *data, char *line);
void		check_cub(char *str);
void		check_xpm(char *path, t_cub3D *data);
void		check_colors2(t_cub3D *data);
void		check_exist(t_cub3D *data);
void		null_init(t_cub3D *data);
void		get_pos_player(t_cub3D *data);
int			check_map(char **map);
int			check_map2(char **map);
int			identifcation(t_cub3D *data, char **tmp);
void		the_ultimate_free(t_cub3D *data);
int			line_check(char *line, t_cub3D *data);
void		fill_texturs(t_cub3D *data);
void		set_position_init(t_cub3D *data, float x, float y);
t_player	*init_player(void);
t_image		*image_init(void);
void		texture_init(t_cub3D *data);
//---------start_mlx----------
int			start_mlx(t_cub3D *data);
void		mlx_put(t_image *image, int x, int y, int color);
void		init_function(t_cub3D *data);
//------------player_movment----------
int			key_release(int key, t_cub3D *data);
int			key_press(int key, t_cub3D *data);
void		move_left(t_cub3D *data);
void		move_right(t_cub3D *data);
void		move_backward(t_cub3D *data);
int			handel_input(t_cub3D *data);
void		move_forward(t_cub3D *data);
void		rotate_right(t_player *p);
void		rotate_left(t_player *p);
//----------utils-------
void		free_image(t_cub3D *data, t_image *image);
void		free_tab(char **tab);
void		ft_error(char *error, t_cub3D *data);
//----------raycast----------
void		ft_raycasting(t_cub3D *data);
void		draw_col(t_cub3D *data);
void		check_calcul(t_cub3D *data);
void		ft_dda(t_cub3D *data);
void		ft_color_init(t_cub3D *data);

#endif
