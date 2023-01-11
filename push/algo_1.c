#include "push_swap.h"

void casses_over_5(t_node **a, t_data *data)
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
		//len2 = len / 5;
		len2 = data->min;
		/*while (len2 <= 100)
		{
			max = len2 - 1;
			boucle(a,b,min,max);
			min = max + 1;
			len2 += 20;
		}*/
		while(data->min <= data->max)
		{
			max = data->min + 20;
			boucle(a, b, data->min, max);
			data->min += 20;
		}
	}
	else
		ft_500(a, b, len);
	ft_display(b);
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

void	min_max(t_node **a, int min, int max)
{
	int hold_first;
	int len;
	int hold_second;

	if ((*a) == NULL)
			return;
	len = len_node(a);
	hold_first = find_first(a,min,max);
	hold_second = find_first_back(a, hold_first, min, max);
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

void checker(t_node **b,t_node *temp)
{
	int len;

	len = len_node(b);
	if ((*b) == NULL)
			return ;
	if (temp->data >= (*b)->data)
				rb(b);
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
