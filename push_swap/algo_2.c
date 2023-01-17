/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:19:09 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/16 16:51:28 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_node **b)
{
	t_node	*temp;
	t_node	*big;
	int		len;
	int		pos;

	pos = 0;
	len = len_node(b) - 1;
	temp = *b;
	big = *b;
	while (temp->next)
	{
		if (temp->data > big->data)
			big = temp;
		temp = temp->next;
	}
	temp = *b;
	while (temp->data != big->data)
	{
		pos++;
		temp = temp->next; 
	}
	return (pos);
}

int	find_smal2(t_node **b)
{
	t_node	*temp;
	t_node	*small;
	int		len;
	int		pos;

	pos = 0;
	len = len_node(b);
	temp = *b;
	small = *b;
	while (len > 0)
	{
		if (temp->data > small->data)
				small = temp;
		temp = temp->next;
		len--;
	}
	temp = *b;
	while (temp->data != small->data)
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

void	finish(t_node **a, t_node **b, int pos, int i)
{
	while (pos--)
		rb(b);
	pa(a, b);
}

void	final_push(t_node **a,t_node **b)
{
	int		pos;
	int		len;
	int		i;

	len = len_node(b);
	while (len--)
	{
		i = len_node(b);
		pos = find_smal2(b);
		if (pos >= i / 2)
		{
			while (pos++ < i)
				rrb(b);
			pa(a, b);
		}
		else if (pos <= i / 2)
			finish(a, b, pos, i);
	}
}

void	ft_500(t_node **a, t_node **b, int len)
{
	int	i;
	int	min;
	int	max;
	int	len2;

	min = 0;
	max = 0;
	i = len / 10;
	len2 = i;
	while (i < 500 + 5)
	{
		max = i - 1;
		boucle(a, b, min, max);
		min = max + 1;
		i = i + len2;
	}
}
