#ifndef F_D_F_H
# define F_D_F_H

#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MLX_ERROR 1
typedef struct	s_img
{
		void	*mlx_img;
		char	*addr;
		int 	bpp;
		int 	line_len;
		int 	endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

#endif
