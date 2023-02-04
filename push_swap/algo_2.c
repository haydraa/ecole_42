/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:19:09 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/17 18:03:51 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_node **b)
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

void	check(t_node **a)
{
	if ((*a)->next == NULL)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

int	find_big_num(t_node **a, int pos)
{
	t_node	*temp;

	temp = *a;
	while (pos)
	{
		temp = temp->next;
		pos--;
	}
	return (temp->data);
}

void	big_1_2(t_node **a, t_node **b, t_data *data)
{
	pa(a, b);
	data->len--;
	data->pos = find_big(b);
	if ((*b)->data == data->big - 2)
	{
		pa(a, b);
		data->index = 1;
		ra(a);
		data->len--;
		data->pos = find_big(b);
	}
}

void	final_push(t_node **a, t_node **b, t_data *data)
{
	data->len = len_node(b);
	while (data->len--)
	{
		data->i = len_node(b);
		data->pos = find_big(b);
		data->big = find_big_num(b, data->pos);
		data->index = 0;
		while ((*b)->data != data->big)
		{
			if (data->pos >= data->i / 2)
				rrb(b);
			else if (data->pos <= data->i / 2)
				rb(b);
			if ((*b)->data == data->big - 1)
				big_1_2(a, b, data);
		}
		pa(a, b);
		check(a);
		if (data->index == 1)
			rra(a);
	}
}
