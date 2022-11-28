
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
void put_in(char *dest, char *src, char space);
int	to_the_last(t_node **a,int min,int max);
void 	check_push(t_node **a,t_node **b,int max);
void	boucle(t_node **a,t_node **b, int min,int max);
void  unreverse(t_node **a);
int	len_node(t_node **list);
void	ft_lstadd_front_node(t_node **list, int data);
t_node **send_to_a(int argc, char **args);
void	ft_lstadd_back_node(t_node **lst, int data);
int ft_doubel(char *str, char *s);
int ft_check_arg(char *arg);
int	ft_assembel(int arg, char **arg1);
int check(char *src);
char	*len_args(int argc, char **argv);
char	*join(int argc, char **argv);
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
void	casses_over_3(t_node **list);
void casses_of_2(t_node **list);
void casses_of_3(t_node **list);
void casses_of_3v2(t_node **list);
void checker(t_node **b, t_node *a ,int max);
void	casses_over_5(t_node **a);
int	find_small(t_node **list, int i);
void delet_node(t_node **hold,int key);
void change(t_node **a, int i, int x);
int	find_first_back(t_node **a ,int min ,int max);
int	find_first(t_node **a, int min, int max);
void	min_max(t_node **a, int min,int max);
int to_dob(char **tab);
void start(int len , char **argv);
int find_big(t_node **b);
int  to_the_last(t_node **a, int min, int max);
void	min_max(t_node **a, int min, int max);
void	ft_500(t_node **a,t_node **b ,int len);

#endif
