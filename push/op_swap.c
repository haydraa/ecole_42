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

void	sb(t_node **b)
{
		t_node 	*a;
		t_node	*tmp;

		if (b == NULL)
			return ;
		a = *b;
		tmp = (*b)->next;
		if (a && b)
		{
				swap(&(a->data), &(tmp->data));
		}
		ft_printf("sb\n");

}

void	sa(t_node **a)
{
		t_node 	*tmp;
		t_node	*b;

		if (a == NULL)
			return ;
		tmp = *a;
		b = (*a)->next;
		if (a && b)
		{
				swap(&(tmp->data), &(b->data));
		}
		ft_printf("sa\n");
}
