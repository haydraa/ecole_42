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

void final_push(t_node **b)
{
	int pos;
	int len;
	int i;
	t_node **a;

	a = malloc(sizeof(t_node*));
	*a = NULL;
	i = 0;
	len = len_node(b);
	while (len)
	{
		i = len_node(b);
		pos = find_big(b);
		if (pos >= i / 2)
		{
			while (pos < i)
			{
				rrb(b);
				pos++;
			}
			pa(a,b);
		}
		else if (pos <= i / 2)
		{
			while(pos)
			{
				rb(b);
				pos--;
			}
			pa(a,b);
		}
		len--;
	}
	//ft_display(a);
	free_node(a);
}

void	ft_500(t_node **a,t_node **b ,int len)
{
	int i;
	int min;
	int max;
	int len2;

	min = 0;
   	max = 0;	
	i = len / 5;
	len2 = i;
	while (i < 500 + 5)
	{
		max = i - 1;
		boucle(a,b,min,max);
		min = max + 1;
		i = i + len2;
	}
}
