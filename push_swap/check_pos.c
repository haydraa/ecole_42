#include "push_swap.h"

int check_pos(t_node **a,t_node **b)
{
	int i;
	t_node *temp;
	t_node *tmp;

	temp = *a;
	tmp = *b;
	while (temp != NULL)
	{
			if (tmp->data > temp->data)
					i++;
			temp = temp->next;		
	}
	return i;
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
