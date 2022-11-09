
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
	struct s_node	*next;
}					t_node;

void	ft_display(t_node **top);
t_node	*in_stack_a(int  value);
int		check_arg(char *argv);
int		ft_doubel(char *str, char *s);
int		ft_assembel(int arg, char **arg1);
t_node 	**send_to_a(int argc, char **args);
void	sa(t_node **list);
void	sb(t_node **list);
void	ss(t_node **a, t_node **b);
void	swap(int *a,int *b);
void	ft_lstadd_back_node(t_node **lst, t_node *new);
t_node	*in_stack_b(int value);
t_node	**send_to_b(int value);
void	pa(t_node **a,t_node **b);
t_node	pb(t_node **a);
void	rrr(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void 	rra(t_node **node);
void	rrb(t_node **node);
void 	ra(t_node **node);
void	rb(t_node **node);
void	ft_free(t_node **list);
void 	len_list(t_node **list);
void	casses_of_3(t_node **list);
void	casses_of_3v2(t_node **list);
void	casses_of_2(t_node **list);
void	casses_over_3(t_node **list);

#endif
