#include "push_swap.h"

void unreverse(t_node **a)
{
	t_node	*current;
	t_node *prev;
	t_node *next;

	current = *a;
	next = NULL;
	prev = NULL;
	while (current != NULL)
	{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
	}
	*a = prev;
}

int	len_node(t_node **list)
{
	int	i;
	t_node *temp;

	i = 0;
	temp = *list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return i;
}


