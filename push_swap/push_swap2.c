#include "push_swap.h"
void ft_check(t_node **a)
{
	t_node	*temp;
	temp = *a;
	if (temp == NULL)
		return ;
	if (temp->next == NULL)
		return ;
	if (temp->data > temp->next->data)
		sa(a);

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
		if (pos > i / 2)
		{
			while (pos < i)
			{
				rrb(b);
				pos++;
			}
			pa(a,b);
			//ft_check(a);
		}
		else if (pos <= i / 2)
		{
			while(pos)
			{
				rb(b);
				pos--;
			}
			pa(a,b);
			//ft_check(a);
		}
		len--;
	}
	ft_free(a);
	free(a);
}

void checker(t_node **b, t_node *a)
{
	t_node *temp;
	int len;
	int pos;

	pos = 0;
	len = len_node(b);
	temp = *b;
	if ((*b) == NULL)
			return ;
	if (a->data > len / 2)
		rb(b);
/*	while (temp)
	{
		if (a->data == temp->data + 1)
			break;
		pos++;
		temp = temp->next;
	}
	if (pos > len / 2)
	{
			while (pos < len)
			{
				rrb(b);
				pos++;
			}
	}
	else if (pos < len/2)
	{
			while (pos--)
				rb(b);
	}*/
}

void casses_over_5(t_node **a)
{
	int len;
	int len2;
	int min;
	int max;
	t_node **b;

	min = 0;
	len = len_node(a);
	b = malloc(sizeof(t_node *));
	*b = NULL;
	if (len < 20)
		boucle(a,b,0,19);
	if (len <= 100)
	{
		len2 = len / 5;
		while (len2 <= 100)
		{
			max = len2 - 1;
			boucle(a,b,min,max);
			min = max + 1;
			len2 += 20;
		}
	}
	else
		ft_500(a, b, len);
	final_push(b);
	free(b);
}

void	boucle(t_node **a, t_node **b,int min,int max)
{
	int p_min;
	int p_max;

	p_min = min;
	p_max = max;
	while (min <= max)
	{
		min_max(a, p_min,p_max);
		check_push(a,b);
		min++;
	}
}

void check_push(t_node **a,t_node **b)
{
	t_node *temp;

	if ((*b) == NULL)
	{
		pb(a,b);
		return ;
	}
	temp = *a;
	if (temp == NULL)
		return ;
	checker(b,temp);
	pb(a,b);
}
