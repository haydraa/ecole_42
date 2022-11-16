#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		t_node *temp;
		temp = *b;
		(*b) = (*b)->next;
		ft_lstadd_front_node(a, temp);
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
		t_node *temp;
		
		temp = *a;
		*a = (*a)->next;
		ft_lstadd_front_node(b,temp);
		ft_printf("pb\n");
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
