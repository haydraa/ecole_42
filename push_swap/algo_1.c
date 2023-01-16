/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:19:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/16 16:51:00 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	casses_over_5(t_node **a, t_data *data)
{
	int		len;
	int		len2;
	int		max;
	int		mid;		
	int		add;
	t_node	**b;

	len = len_node(a);
	b = malloc(sizeof(t_node *));
	*b = NULL;
	mid = data->min - data->max;
	add = mid / 5;
	if (add < 0)
		add *= -1;
	if (len <= 100)
	{
		len2 = data->min;
		while (data->min <= data->max)
		{
			max = data->min + add;
			boucle(a, b, data->min, max);
			data->min += add;
		}
	}
	else
		ft_500(a, b, len);
	final_push(b);
	free(b);
}

void	boucle(t_node **a, t_node **b, int min, int max)
{
	int	p_min;
	int	p_max;

	p_min = min;
	p_max = max;
	while (min <= max)
	{
		min_max(a, p_min, p_max);
		check_push(a, b);
		min++;
	}
}

void	min_max(t_node **a, int min, int max)
{
	int	hold_first;
	int	len;
	int	hold_second;

	if ((*a) == NULL)
		return ;
	len = len_node(a);
	hold_first = find_first(a, min, max);
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

void	checker(t_node **b, t_node *temp)
{
	int	len;

	len = len_node(b);
	if ((*b) == NULL)
		return ;
	if (temp->data >= (*b)->data)
		rb(b);
}

void	check_push(t_node **a,	t_node **b)
{
	t_node	*temp;

	if ((*b) == NULL)
	{
		pb(a, b);
		return ;
	}
	temp = *a;
	if (temp == NULL)
		return ;
	checker(b, temp);
	pb(a, b);
}
