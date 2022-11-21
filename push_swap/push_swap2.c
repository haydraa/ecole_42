#include "push_swap.h"

int checker(t_node **b, t_node *a)
{
	t_node *temp;
	int pos;
	int len;

	pos = 0;
	len = len_node(b);
	temp = *b;
	while (temp != NULL)
	{	
		if(temp->data < a->data)
				return pos;
		else
			temp = temp->next;
	}
	return pos;
}

void casses_over_5(t_node **a)
{
	int len;
	int min;
	int max;
	int len2;

	min = 0;
	len = len_node(a);
	if (len < 20)
		min_max(a,0,19);
	else if (len <= 100)
	{
		len = len / 5;
		while(len <= 100)
		{
			max = len - 1;
			min_max(a,min,max);
			min = max;
			len = len + 20;
		}
	}
	else if (len <= 5)
	{
		len = len / 11;
		len2 = len;
		while (len <= 500)
		{
			max = len -1;
			min_max(a,min,max);
			min = max;
			len = len + len2;
		}
	}
		
		
}

void check_push(t_node **a,t_node **b)
{
	t_node *temp_a;
	t_node *temp_b;
	int pos;

	if ((*b) == NULL)
		pb(a,b);
	else 
	{
		pos = checker(b,temp_a);
		while (pos)
		{
			rb(b);
			pos--;
		}
		pb(a,b);
	}
	ft_display(b);
}


void	min_max(t_node **a, int min, int max)
{
	t_node **b;
	int hold_first;
	int len;
	int hold_second;
	int all;
	int len2;

	
	b = malloc(sizeof(t_node *));
	*b = NULL;
	len = len_node(a);
	len2 = max;
	all = len / 2;
	while (len2)
	{
		hold_first = find_first(a,min,max);
		hold_second = find_first_back(a,min,max);
		if (hold_first == len)
			pb(a,b);
		else if (hold_second - len > hold_first)
		{
			while (hold_first)
			{
				ra(a);
				hold_first--;
			}
		}
		else if (hold_second - len < hold_first)
		{
			while (hold_second < len)
			{
				rra(a);
				hold_second++;
			}
		}
		check_push(a,b);
		len2--;
	}
}
