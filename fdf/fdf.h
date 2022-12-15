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

//struct
//bpp = bite_per_pixel 
typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
}			t_mlx;


typedef struct s_glob
{
	int i;
	int j;
	int steps;
}	t_glob;

typedef struct s_tab
{
	int **tab;
	int core_x;
	int core_y;
}		t_tab;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}		t_data;

typedef struct s_dda
{
	int		dx;
	int		dy;
	float	xinc;
	float	yinc;
	float	X;
	int color;
	float	Y;
	int z;
	int z1;	
	float x0;
	float x1;
	float y0;
	float y1;

	int zoom;
}			t_dda;
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

//fdf
void dis(int **tab,char *file);
int size_x(char *file);
int size_y(char *file);
void malloc_map(char *file, t_tab *tab);
void fil_tab(int *tab, char *line, int x);
void to_tab(int fd, t_tab *tab, char *file);
void in_img(t_mlx *mlx, char *file, t_tab *tab);
void ft_dda(t_data img, t_dda *dda /*float x0, float y0, float x1 ,float y1*/,t_tab *tab);
void open_win(char *file,t_tab *tab);
void	mlx_put(t_data *data, int x, int y, int color);
int handle_input(int keysym,t_mlx *mlx);
int handle_no_even(void *data);
void isometric(float *x,float *y,int z);
void in_struct(t_dda *dda, int i, int j,int index);
void isometric(float  *x,float *y,int  z);
void zoom(t_dda *dda);
void get_place(t_dda *dda);
void color_rgb(t_dda *dda, t_tab *tab);
void in_struct(t_dda *dda, int  i,int  j, int index);

#endif
