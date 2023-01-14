/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:20:46 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 11:20:47 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_algo(t_node **a, t_data *data)
{
	t_node	*temp;
	int		i;

	i = len_node(a);
	temp = *a;
	if (i == 1)
		return ;
	else if (i == 2)
		casses_of_2(a);
	else if (i == 3)
		casses_of_3(a);
	else if (i > 3 && i < 6)
		casses_over_3(a, data);
	else if (i > 5)
		casses_over_5(a, data);
}

void	casses_over_3(t_node **a, t_data *data)
{
	t_node	**b;
	int		x;
	int		pos;
	int		len;

	x = 2;
	b = malloc(sizeof(t_node *));
	*b = NULL;
	while (x > 0)
	{
		len = len_node(a);
		if (len == 3)
			break ;
		pos = find_small(a, len);
		casses_for3(a, b, pos, len);
		x--;
	}
	to_algo(a, data);
	x = len_node(b);
	while (x--)
		pa(a, b);
	free(b);
}

void	casses_of_2(t_node **a)
{
	t_node	*temp;

	temp = *a;
	if (temp->data > temp->next->data)
	{
		sa(a);
		return ;
	}
}

void	casses_of_3(t_node **a)
{
	t_node	*temp;

	temp = *a;
	if (temp->data > temp->next->data)
	{
		temp = temp->next;
		if (temp->data > temp->next->data)
		{
			sa(a);
			rra(a);
		}
		else if (temp->data < temp->next->data && (*a)->data > temp->next->data)
			ra(a);
		else if (temp->data < temp->next->data)
			sa(a);
	}
	else
		(casses_of_3v2(a));
}

void	casses_of_3v2(t_node **a)
{
	t_node	*temp;

	temp = *a;
	if (temp->data < temp->next->data)
	{
		temp = temp->next;
		if (temp->data > temp->next->data && temp->next->data > (*a)->data)
		{
			sa(a);
			ra(a);
			return ;
		}
		if (temp->next->data < (*a)->data && temp->next->data < (*a)->data)
		{
			rra(a);
			return ;
		}
	}
}
