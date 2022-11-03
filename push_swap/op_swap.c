#include "push_swap.h"

void	swap(int *a, int *b)
{
		int temp;

		temp = *a;
		*a = *b;
		*b = temp;
}

void	sawp_a(t_node **list)
{
		t_node 	*a;
		t_node	*b;
		t_node	temp;

		if (list == NULL)
			return ;
		a = *list;
		b = (*list)->next;
		if (a && b)
		{
				swap(&(a->data), &(b->data));
				//swap(((*a)->next),((*b)->next));
		}
		ft_printf("sa\n");
		
}
