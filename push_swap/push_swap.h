
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct node
{
		int 			data;
		struct node	*next;
}						t_node;

void	ft_display(t_node *top);
t_node	*in_stack_a(int  value);
int		check_arg(char *argv);
int		ft_doubel(char *str, char *s);
int		ft_assembel(int arg, char **arg1);
void 	send_to_stack(char **args);
void	sawp_a(t_node **list);
void	swap(t_node *a, t_node *b);

#endif
