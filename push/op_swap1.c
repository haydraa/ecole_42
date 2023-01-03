#include "push_swap.h"

void ra(t_node **a)
{
		if (*a == NULL || (*a)->next == NULL)
				return ;
		t_node *first;
		t_node *last;
		
		first = *a;
		last = *a;
		while (last->next != NULL)
			last = last->next;
		*a = first->next;
		first->next = NULL;
		last->next = first;
		first->prev = last;
		ft_printf("ra\n");
}

void rb(t_node **b)
{
		if (*b == NULL || (*b)->next == NULL)
				return ;
		t_node	*first;
		t_node	*last;

		first = *b;
		last = *b;
		while (last->next != NULL)
				last = last->next;
		*b = first->next;
		first->next = NULL;
		last->next = first;
		first->prev = last;
		ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
void rra(t_node **a)
{
		if (*a == NULL || (*a)->next == NULL)
				return ;
		t_node	*temp;
		t_node	*last;

		temp = NULL;
		last = *a;
		while (last->next != NULL)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *a;
		last->prev = NULL;
		*a = last;
		ft_printf("rra\n");
}

void rrb(t_node **b)
{
		if (*b == NULL || (*b)->next == NULL)
				return ;
		t_node	*temp;
		t_node	*last;

		temp = NULL;
		last = *b;
		while (last->next != NULL)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *b;
		last->prev = NULL;
		*b = last;
		ft_printf("rrb\n");
}
