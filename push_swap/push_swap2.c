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

void check_push(t_node **a,t_node **b)
{
	t_node *temp_a;
	t_node *temp_b;
	int pos;
	int len;

	pos = 0;
	temp_b = *b;
	temp_a = *a;
	if (temp_b->next == NULL)
	{	
		pb(a,b);
		return ;
	}
	len = len_node(b);
	pos = checker(b, temp_a);
	if (pos == 0)
			pb(b,a);
	else 
	{
		if (pos <= len / 2)
		{
			while(pos)
			{
				rb(b);
				pos--;
			}
			pb(b,a);
		}
		else if (pos >= len / 2)
		{
				while(pos)
				{
					rrb(b);
					pos--;
				}
				pb(b,a);
		}
	}
}


void	casses_over_5(t_node **a)
{
	t_node **b;
	int hold_first;
	int len;
	int hold_second;
	int all;
	
	b = malloc(sizeof(t_node *));
	*b = NULL;
	len = len_node(a);
	all = len / 2;
	while (len)
	{
		hold_first = find_first(a,0,19);
		hold_second = find_first_back(a,0,19);
		if (hold_first > hold_second)
		{
			while(hold_second > 0)
			{
				rra(a);
				hold_second--;
			}
			pb(a,b);
		}
		else
		{
			while(hold_first > 0)
			{
				ra(a);
				hold_first--;
			}
		}
		check_push(a,b);
		//ft_display(a);
		//ft_display(b);
		len--;
	}
}
