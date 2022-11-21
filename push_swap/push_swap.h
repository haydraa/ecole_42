
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
	struct s_node	*next;
}					t_node;

void  unreverse(t_node **a);
int	len_node(t_node **list);
void	ft_lstadd_front_node(t_node **list, t_node *new);
t_node	*in_stack_a(int value);
t_node **send_to_a(int argc, char **args);
void	ft_lstadd_back_node(t_node **lst, t_node *new);
int ft_doubel(char *str, char *s);
int ft_check_arg(char *arg);
int	ft_assembel(int arg, char **arg1);
void join(char *dest, char *src, char space);
int check(char *src);
char	**assembel(int argc, char **argv);
int check_list(t_node **list);
void ft_display(t_node **top);
void ft_free(t_node **list);
void	swap(int *a, int *b);
void ss(t_node **a, t_node **b);
void	sb(t_node **list);
void	sa(t_node **list);
void ra(t_node **node);
void rb(t_node **node);
void rr(t_node **a, t_node **b);
void rra(t_node **node);
void rrb(t_node **node);
void pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void rrr(t_node **a, t_node **b);
void len_list(t_node **list);
void	casses_over_3(t_node **list, int i);
void casses_of_2(t_node **list);
void casses_of_3(t_node **list);
void casses_of_3v2(t_node **list);
int checker(t_node **b, t_node *a);
void check_push(t_node **a,t_node **b);
void	casses_over_5(t_node **a);
int	find_small(t_node **list, int i);
void delet_node(t_node **hold,int key);
void change(t_node **a, int i, int x);
int	find_first_back(t_node **a ,int min ,int max);
int	find_first(t_node **a, int min, int max);

#endif
