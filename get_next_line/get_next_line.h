#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE  
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		found_line(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	extract_line(t_list *stash, char **line);
void	read_and_stash(int fd, t_list **stach);
void	add_to_stash(t_list **stash, char *buff, int readed);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
void	free_stash(t_list *stash);
int		len(char *str);

#endif
