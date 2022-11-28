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
		if (pos > i / 2)
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
	while (temp)
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
	}
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
	while (i <= 500)
	{
		max = i - 1;
		boucle(a,b,min,max);
		min = max + 1;
		i = i + len2;
		if (i > 500)
				i = i - 501;
	}
}
void casses_over_5(t_node **a)
{
	int len;
	int min;
	int max;
	t_node **b;

	min = 0;
	len = 0;
	len = len_node(a);
	b = malloc(sizeof(t_node *));
	*b = NULL;
	if (len < 20)
		boucle(a,b,0,19);
	if (len <= 100)
	{
		len = (len / 10);
		max = len;
		while(max < 80)
		{
			max = len - 1;	
			boucle(a,b,min,max);
			if (to_the_last(a,min,max) == 0)
				boucle(a,b,min,max);
			min = max + 1;
			len = len + 20;
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

	if ((*a) == NULL)
		return ;
	if ((*b) == NULL)
	{
		pb(a,b);
		return ;
	}
	temp = *a;
	checker(b,temp);
	pb(a,b);
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
