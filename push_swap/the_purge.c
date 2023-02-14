/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_purge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:21:28 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 11:21:30 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node **a)
{
	t_node	*temp;
	t_node	*hold;

	temp = *a;
	while (temp)
	{
		hold = temp;
		temp = temp->next;
		free(hold);
	}
	free(a);
}

void	casses_for3(t_node **a, t_node **b, int pos, int len)
{
	if (pos <= 3)
	{
		while (pos--)
			ra(a);
		pb(a, b);
	}
	if (pos == 0)
		pb(a, b);
	else if (pos == len - 1)
	{
		rra(a);
		pb(a, b);
	}
}

int	find_small(t_node **list, int i)
{
	t_node	*temp;
	t_node	*small;
	int		len;
	int		x;

	x = 0;
	len = i;
	temp = *list;
	small = *list;
	while (len > 0)
	{
		if (temp->data < small->data)
			small = temp;
		temp = temp->next;
		len--;
	}
	temp = *list;
	while (temp->data != small->data)
	{
		x++;
		temp = temp->next;
	}
	return (x);
}

int	find_first_back(t_node **a, int min, int max, int holded)
{
	t_node	*temp;
	int		pos;

	if ((*a) == NULL)
		return (0);
	pos = 0;
	temp = *a;
	while (temp->next)
	{
		if (temp->data >= min && temp->data <= max && temp->data != holded)
			break ;
		temp = temp->next;
		pos++;
	}
	return (pos);
}

int	find_first(t_node **a, int min, int max)
{
	t_node	*temp;
	int		pos;

	pos = 0;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->data >= min && temp->data <= max)
			break ;
		else
		{
			temp = temp->next;
			pos++;
		}
	}
	return (pos);
}
