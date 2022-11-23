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
int  to_the_last(t_node **a, int min, int max)
{
	t_node	*temp;
	temp = *a;
	if (*a == NULL)
		return 1;
	if (temp->data > max || temp->data < min)
		return 2;
	while (temp)
	{
		if (temp->data > min && temp->data < max)
			return 0;
		temp = temp->next;
	}
	return 1;
}

void casses_over_5(t_node **a)
{
/*	int len;
	int min;
	int max;
	int len2;*/
	t_node **b;

/*	min = 0;
	len = 0;
	len = len_node(a);*/
	b = malloc(sizeof(t_node *));
	*b = NULL;
//	if (len < 20)*/
		boucle(a,b,0,20);
/*	if (len <= 100)
	{
		len = (len / 5);
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
	//ft_printf("\n");
//	ft_display(b);
}

void	boucle(t_node **a, t_node **b,int min,int max)
{
	int p_min;
	int p_max;

	p_min = min;
	p_max = max;
	while (min <= max +3 )
	{
		min_max(a, p_min,p_max);
		check_push(a,b);
	//	if (to_the_last(a,min,max) == 2)
	//		min--;
		min++;
	}
		
//	ft_display(a);	
	ft_display(b);
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
//	int all;
	
	if ((*a) == NULL)
			return;
	len = len_node(a);
//	all = len / 2;
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
