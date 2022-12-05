#ifndef F_D_F_H
# define F_D_F_H

#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <fcntl.h>
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
//get_next_line
char	*get_next_line(int fd);
int		ft_find_line(t_list *stash);
t_list	*ft_to_end(t_list *stash);
void	ft_get_line(t_list *stash, char **line);
void	ft_read_stock(int fd, t_list **stach);
void	ft_add(t_list **stash, char *buff, int buffer);
void	ft_create_line(char **line, t_list *stash);
void	ft_clean(t_list **stash);
void	ft_free(t_list *stash);
int		len(char *str);

#endif
