/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:46:19 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:46:22 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_D_F_H
# define F_D_F_H

#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <math.h>
#include <fcntl.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 900
#define MLX_ERROR 1
#define ANGLE 0.8

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;

	int i;
	int j;
	int steps;
	int shift_x;
	int shift_y;
	
	int **tab;
	char *file;
	int core_x;
	int core_y;
	int **repair;

	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;

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
	
}	t_fdf;

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
void malloc_map(t_fdf *data);
void fil_tab(int *tab, char *line, int x);
void to_tab(int fd, t_fdf *data);
void in_img(t_fdf *data);
void ft_dda(t_fdf *data);
void open_win(t_fdf *data);
void	mlx_put(t_fdf *data, int x, int y, int color);
int handle_input(int keysym,t_fdf *data);
int handle_no_even(void *data);
void isometric(float *x,float *y,int z);
void in_struct(t_fdf *data, int i, int j,int index);
void isometric(float  *x,float *y,int  z);
void zoom(t_fdf *data);
void get_place(t_fdf *data);
void color_rgb(t_fdf *data);
void in_struct(t_fdf *data, int  i,int  j, int index);
int handle_no_even(void *data);
int handle_input(int keysym, t_fdf *data);
void change_tab(t_fdf *data, int index);
void repair(t_fdf *data);
void the_free(t_fdf *data);
int  ft_close(t_fdf *data);
# endif
