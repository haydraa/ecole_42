/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:02:23 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 18:57:46 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# if BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE		
#  define BUFFER_SIZE 8000000
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	char			*content;
	int				i;
	int				j;
	struct s_gnl	*next;
}					t_gnl;

char	*get_next_line(int fd);
int		ft_find_line(t_gnl *stash);
t_gnl	*ft_to_end(t_gnl *stash);
void	ft_get_line(t_gnl *stash, char **line);
void	ft_read_stock(int fd, t_gnl **stach);
void	ft_add(t_gnl **stash, char *buff, int buffer);
void	ft_create_line(char **line, t_gnl *stash);
void	ft_clean(t_gnl **stash);
void	ft_free_gnl(t_gnl *stash);
int		len(char *str);

#endif
