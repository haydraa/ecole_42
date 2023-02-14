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
	t_node	**b;

	len = len_node(a);
	b = malloc(sizeof(t_node *));
	if (!b)
		return ;
	*b = NULL;
	data->max = len / 5;
	data->min = 0;
	if (len <= 100)
	{
		while (data->min <= len)
		{
			data->max = data->min + 25;
			boucle(a, b, data->min, data->max);
			data->min += 25;
		}
	}
	else if (len > 100 && len <= 500)
		ft_500(a, b, len);
	else
		the_rest(a, b, len);
	final_push(a, b, data);
	free(b);
}

void	ft_500(t_node **a, t_node **b, int len)
{
	int	i;
	int	min;
	int	max;
	int	len2;

	min = 0;
	max = 0;
	i = len / 8;
	len2 = i;
	while (i < len)
	{
		max = i - 1;
		boucle(a, b, min, max);
		min = max + 1;
		i = i + len2;
	}
	i = 0;
	while (i < 4)
	{
		pb(a, b);
		i++;
	}
}

void	the_rest(t_node **a, t_node **b, int len)
{
	int	min;
	int	max;
	int	div;
	int	div2;
	int	div3;

	div = len / 10;
	div2 = div * 10;
	div3 = len - div2;
	div2 = div;
	min = 0;
	while (min <= len)
	{
		max = div - 1;
		boucle(a, b, min, max);
		min = max + 1;
		div += div2;
	}
}

void	boucle(t_node **a, t_node **b, int min, int max)
{
	t_data	data;

	data.index = 0;
	data.p_min = min;
	data.p_max = max;
	while (min <= max)
	{
		min_max(a, b, &data);
		if (data.index == 0)
			min++;
		else
			min += data.index;
	}
}
