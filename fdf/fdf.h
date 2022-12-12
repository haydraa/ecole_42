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
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_vars;
typedef struct s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}		t_data;



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
int **malloc_map(char *file);
void fil_tab(int *tab, char *line, int x);
void to_tab(int fd, int **tab, char *file);

#endif
