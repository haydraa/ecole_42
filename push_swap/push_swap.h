
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
	struct s_node	*next;
}					t_node;

void	ft_display(t_node *top);
t_node	*in_stack_a(int  value);
int		check_arg(char *argv);
int		ft_doubel(char *str, char *s);
int		ft_assembel(int arg, char **arg1);
void 	send_to_a(int argc, char **args);
void	sawp_a(t_node **list);
void	swap(int *a,int *b);
void	ft_lstadd_back_node(t_node **lst, t_node *new);
t_node	*in_stack_b(int value);
void	send_to_b(t_node **node, int i);

#endif
