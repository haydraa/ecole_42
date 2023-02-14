#include "push_swap.h"

void	del(t_node *temp, t_node *prev, int key)
{
	while (prev != NULL)
	{
		if (prev->next->data == key)
		{
			temp = prev->next;
			prev->next = prev->next->next;
			free(temp);
			break ;
		}
		else
			prev = prev->next;
	}
}

void	delet_node(t_node **hold, int key)
{
	t_node	*temp;
	t_node	*prev;
	int		j;

	j = len_node(hold);
	temp = *hold;
	prev = *hold;
	if (temp->data == key)
	{
		(*hold) = (*hold)->next;
		free(temp);
	}
	else
		del(temp, prev, key);
}

void	change_st(t_node **a, t_node **hold, int i, int j)
{
	t_node	*temp;
	t_node	*temp2;
	int		x;
	int		pos;

	x = 0;
	while (i > 0)
	{
		temp2 = *a;
		temp = *hold;
		pos = find_small(hold, i);
		while (temp && x < pos)
		{
			temp = temp->next;
			x++;
		}
		x = 0;
		while (temp2->data != temp->data)
			temp2 = temp2->next;
		delet_node(hold, temp->data);
		temp2->data = j;
		j++;
		i--;
	}
}

void	change(t_node **a, int i)
{
	t_node	*temp;
	t_node	**hold;
	int		pos;
	int		j;

	j = 0;
	hold = malloc(sizeof(t_node *));
	if (!hold)
		return ;
	*hold = NULL;
	temp = *a;
	while (temp != NULL)
	{
		pos = temp->data;
		ft_lstadd_back_node(hold, pos);
		temp = temp->next;
	}
	change_st(a, hold, i, j);
	free(hold);
}
