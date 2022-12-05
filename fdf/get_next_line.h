/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:02:23 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/31 12:57:13 by jghribi          ###   ########.fr       */
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
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

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
