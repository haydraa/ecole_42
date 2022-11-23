#include "push_swap.h"

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
		if (temp->data + 1 == a->data)
				break ;
		temp = temp->next;
		pos++;
	}				
}

void casses_over_5(t_node **a)
{
/*	int len;
	int min;
	int max;
	int len2;*/
	t_node **b;

//	min = 0;
//	len = 0;
//	len = len_node(a);
	b = malloc(sizeof(t_node *));
/*	*b = NULL;
	if (len < 20)*/
		boucle(a,b,20,39);
	/*if (len <= 100)
	{
		len = (len / 5);
		max = len;
		while(max < 100)
		{
			max = len - 1;	
			boucle(a,b,min,max);
			min = max + 1;
			len = len + 20;
		}
	}
	else if (len > 100)
	{
		len = len / 11;
		len2 = len;
		while (len <= 500)
		{
			max = len -1;
			boucle(a,b,min,max);
			min = max;
			len = len + len2;
		}
	}*/
	ft_display(b);
	//ft_printf("\n");
	//ft_display(a);
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
		return;
	}
	temp = *a;
	//checker(b,temp);
	pb(a,b);
}

void	min_max(t_node **a, int min, int max)
{
	int hold_first;
	int len;
	int hold_second;
	int all;
	int len2;
	
	len = len_node(a) - 1;
	len2 = max;
	all = len / 2;
	hold_first = find_first(a,min,max);
	hold_second = find_first_back(a,min,max);
	if ((*a) == NULL)
			return;
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
