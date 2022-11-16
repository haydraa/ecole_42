#include "push_swap.h"

int	find_small(t_node **list, t_node *first, int i)
{
	t_node	*temp;
	t_node	*small;
	int		len;
	int		x;

	x = 0;
	len = i;
	temp = *list;
	small = *list;
	while (len > 0)
	{
		if (small->data > temp->data || small == first)
		{
			small = temp;
		}
		temp = temp->next;
		len--;
 	}
	temp = *list;
 	while (temp->data != small->data)
	{
		x++;
		temp = temp->next;
	}
	return x;
}
