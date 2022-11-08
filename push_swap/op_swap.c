#include "push_swap.h"

void	swap(int *a, int *b)
{
		int temp;

		temp = *a;
		*a = *b;
		*b = temp;
}

void ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	sb(t_node **list)
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
		}
		ft_printf("sb\n");
		
}

void	sa(t_node **list)
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
		}
		ft_printf("sa\n");		
}
