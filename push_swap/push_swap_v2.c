#include "push_swap.h"

int find_big(t_node **b)
{
	t_node *temp;
	int len;
	int pos;

	pos = 0;
	len = len_node(b) - 1;
	temp = *b;
	while(temp->next)
	{
		if (temp->data == len)
			break;
		pos++;
		temp = temp->next;
	}
	return pos;
}

int  to_the_last(t_node **a, int min, int max)
{
	t_node	*temp;
	temp = *a;
	if (*a == NULL)
		return 1;
	while (temp)
	{
		if (temp->data > min && temp->data < max)
			return 0;
		temp = temp->next;
	}
	return 1;
}

void	min_max(t_node **a, int min, int max)
{
	int hold_first;
	int len;
	int hold_second;
	
	if ((*a) == NULL)
			return;
	len = len_node(a);
	hold_first = find_first(a,min,max);
	hold_second = find_first_back(a,min,max);
	if (len - hold_second > hold_first)
	{
		while (hold_first > 0)
		{
			ra(a);
			hold_first--;
		}
	}
	else
	{
		while (hold_second <= len)
		{
			rra(a);
			hold_second++;
		}
	}
}

void	ft_500(t_node **a,t_node **b ,int len)
{
	int i;
	int min;
	int max;
	int len2;

	min = 0;
   	max = 0;	
	i = len / 11;
	len2 = i;
	while (i < 500)
	{
		max = i - 1;
		boucle(a,b,min,max);
		min = max + 1;
		i = i + len2;
	}
}
