

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

# if BUFFER_SIZE > 8000000
    # undef BUFFER_SIZE		
    # define BUFFER_SIZE 8000000
#endif	

typedef struct s_list
{
    char			*content;
    struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_find_line(t_list *stash);
t_list	*ft_last(t_list *stash);
void	ft_get_line(t_list *stash, char **line);
void	ft_read_stock(int fd, t_list **stach);
void    ft_add(t_list **stash, char *buff, int readed);
void	ft_create_line(char **line, t_list *stash);
void	ft_clean(t_list **stash);
void	ft_free(t_list *stash);
int		len(char *str);

#endif
