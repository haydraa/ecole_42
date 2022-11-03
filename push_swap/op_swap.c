#include "push_swap.h"

void	swap(t_node* a, t_node* b)
{
		t_node temp;

		temp = *a;
		*a = *b;
		*b = temp;
}

void	sawp_a(t_node **list)
{
		t_node 	**a;
		t_node	**b;
		t_node	temp;

		if (list == NULL)
			return ;
		a = list;
		list = &((*list)->next);
		b = list;
		if (a && b)
		{
				swap(*a, *b);
				swap(((*a)->next),((*b)->next));
		}
		ft_printf("sa\n");
}
