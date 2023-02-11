/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:22:02 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/11 16:35:49 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_data
{
	char	*final_trim;
	char	*final;
	char	**all_final;
	int		min;
	int		max;
	int		p_min;
	int		p_max;
	int		pos;
	int		len;
	int		i;
	int		big;
	int		index;
}				t_data;

char	*join(int argc, char **argv);
void	put_in(char *dest, char *src, char space);
char	*len_args(int argc, char **argv);
int		ft_doubel(int str, int s);
int		ft_check_arg(char *arg);
int		to_dob(char **tab);
void	ft_free(char **tab);
void	start(int len, t_data *data);
void	free_node(t_node **a);
void	ft_lstadd_back_node(t_node **lst, int data);
t_node	**send_to_a(int len, t_data *data);
int		find_small(t_node **list, int i);
int		len_node(t_node **list);
void	to_algo(t_node **a, t_data *data);
void	casses_over_3(t_node **a, t_data *data);
void	casses_of_2(t_node **a);
void	casses_of_3(t_node **a);
void	casses_of_3v2(t_node **a);
void	ft_lstadd_front_node(t_node **list, int data);
void	casses_over_5(t_node **a, t_data *data);
void	boucle(t_node **a, t_node **b, int min, int max);
int		find_first_back(t_node **a, int min, int max, int holded);
void	the_rest(t_node **a, t_node **b, int len);
int		find_first(t_node **a, int min, int max);
void	min_max(t_node **a, t_node **b, t_data *data);
void	check_push(t_node **a, t_node **b);
void	final_push(t_node **a , t_node **b, t_data *data);
void	boucle(t_node **a, t_node **b, int min, int max);
int		find_big(t_node **b);
void	ft_500(t_node **a, t_node **b, int len);
void	checker(t_node **a, t_node **b, t_node *temp);
void	casses_for3(t_node **a, t_node **b, int pos, int len);
void	swap(int *a, int *b);
void	ss(t_node **a, t_node **b);
void	sb(t_node **b);
void	sa(t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	change(t_node **a, int i);

#endif
