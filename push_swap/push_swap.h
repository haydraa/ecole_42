
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct node
{
		int 			data;
		struct node	*next;
}						t_node;

void	*ft_creat_stack(int  value);
int		check_arg(char *argv);
int		ft_doubel(char *str, char *s);
int		ft_assembel(int arg, char **arg1);

#endif
