#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		if(*b == NULL)
			return ;

		ft_front_node(a, *b);
		*b = (*b)->next;
		ft_printf("pa\n");
}

void pb(t_node **a, t_node **b)
{
		if (*a == NULL)
				return ;
		ft_front_node(b, *a);
		*a = (*a)->next;
		ft_printf("pb\n");
}
void	ft_front_node(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	new -> next = new;
	new -> next = (*lst);
	(*lst) = new;
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
