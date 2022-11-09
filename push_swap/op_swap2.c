#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		if(*b == NULL)
			return ;

		*b = (*b)->next;
		ft_printf("pa\n");
}

t_node	pb(t_node **a)
{
		t_node **b;
		t_node *temp;
		int i;

		temp = *a;
		i = temp->data;
		*a = (*a)->next;
		b = send_to_b(i);
		ft_printf("pb\n");
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
