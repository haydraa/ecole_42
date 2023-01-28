/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:19:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/16 19:08:57 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	casses_over_5(t_node **a, t_data *data)
{
	int		len;
	int		len2;
	int		max;
	int		min;		
	int		add;
	t_node	**b;

	len = len_node(a);
	b = malloc(sizeof(t_node *));
	*b = NULL;
	max = len / 5;
	min = 0;
	if (len <= 100)
	{
		while (min <= len)
		{
			max = min + 20;
			boucle(a, b, min, max);
			min += 20;
		}
	}
	else
		ft_500(a, b, len);
	final_push(a,b);
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
	if (temp->data <= (*b)->data)
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
