#include "push_swap.h"

int find_big2(t_node **b)
{
	t_node *temp;
	int len;
	int pos;
	pos = 0;
	len =  len_node(b) - 1;
	temp = *b;
	while (temp->next)
	{
		if (temp->data == lem)
			break;
		pos++;
		tmp == temp->next;
	}
	return pos;
}
void check(t_node **b, int index)
{
	if (index == 0 || (*b)->next == NULL)
		return;
	else
		sb(b);
}
void thr_ultimate_final(t_node **b, int pos, int index);
{
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
	check(b , index);
}
void final_push(t_node **b)
{
	int pos;
	int len;
	int i;
	int pos2;
	int x;
	int y;
	t_node **a;
	
	a = malloc(sizeof(t_node*));
	*a = NULL;
	i = 0;
	len = len_node(b);
	while (len)
	{
		i = len_node(b);
		pos = find_big(b);
		pos2 = find_big2(b);
		if (pos - i > pos1 - i)
		{
			the_ultimate_final(b, pos1, 0);
			the_ultimate_final(b, pos , 1);
		}
		else if (pos - i < pos1 - i)
		{
			the_ultimate_final(b, pos , 1);	
			the_ultimate_final(b, pos1, 0);
		}
	}
//	ft_display(a);
}
