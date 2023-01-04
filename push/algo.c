#include "push_swap.h"

void to_algo(t_node **a)
{
		t_node *temp;
		int i;

		i = len_node(a);
		temp = *a;
		if (i == 1)
				return ;
		else if (i == 2)
			casses_of_2(a);
		else if (i == 3)
				casses_of_3(a);
		else if (i > 3 && i < 6)
			casses_over_3(a);
		else if ( i > 5)
			casses_over_5(a);
}

void	casses_over_3(t_node **a)
{	
	t_node **b;
	int		x;
	int		pos;
	int		len;

	x = 2;
	b = malloc(sizeof(t_node *));
	*b = NULL;
	while(x > 0 )
	{
		len = len_node(a);
		if (len == 3)
			break ;
		pos = find_small(a, len);
		if (pos <= 3)
		{
			while(pos--)
				ra(a);
			pb(a,b);
		}
		if (pos == 0)
			pb(a,b);
		else if (pos == len - 1)
		{
			rra(a);
			pb(a,b);
		}
		x--;
	}
	to_algo(a);
	x = len_node(b);
	while (x--)
		pa(a,b);
	free(b);
}
void casses_of_2(t_node **a)
{
		t_node *temp;

		temp = *a;
		if (temp->data > temp->next->data)
		{
				sa(a);
				return ;
		}
}

void casses_of_3(t_node **a)
{
	t_node *temp;

	temp = *a;
	if (temp->data > temp->next->data)	
	{
		temp = temp->next;
		if(temp->data > temp->next->data)
		{
				sa(a);
				rra(a);
		}
		else if (temp->data < temp->next->data && (*a)->data > temp->next->data)
		{
				ra(a);
		}
		else if (temp->data < temp->next->data)
		{
				sa(a);
		}
	}
	else 
		(casses_of_3v2(a));
}

void casses_of_3v2(t_node **a)
{
	t_node *temp;
	
	temp = *a;
	if (temp->data < temp->next->data)
	{
			temp = temp->next;
			if (temp->data > temp->next->data && temp->next->data > (*a)->data)
			{
					sa(a);
					ra(a);
					return ;
			}
			if (temp->next->data < (*a)->data && temp->next->data < (*a)->data)
			{
					rra(a);
					return ;
			}
	}
}