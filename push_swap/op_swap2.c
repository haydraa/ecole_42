#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		if(*b == NULL)
			return ;
		 
		*b = (*b)->next;
		ft_printf("pa\n");
}

t_node	*pb(t_node **a)
{
		t_node *temp;
		t_node *new;
		int i;
		
		temp = *a;
		i = temp->data;
		new = in_stack_b(i);
		*a = (*a)->next;
		ft_printf("pb\n");
		return new;
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
