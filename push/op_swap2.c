#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		int i;
		t_node *temp;

		temp = *b;
		i = temp->data;
		(*b) = (*b)->next;
		ft_lstadd_front_node(a, i);
		free(temp);
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
		t_node *temp;
		int i;

		temp = *a;
		i = temp->data;
		*a = (*a)->next;
		ft_lstadd_front_node(b,i);
		free(temp);
		ft_printf("pb\n");
}
void	ft_lstadd_front_node(t_node **list, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = (*list);
	new->prev = NULL;
	if ((*list) != NULL)
		(*list)->prev = new;
	(*list) = new;
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
