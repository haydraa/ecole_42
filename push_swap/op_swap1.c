/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:19:29 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 11:19:31 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	first = *a;
	last = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_node **a)
{
	t_node	*temp;
	t_node	*last;

	temp = NULL;
	last = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	t_node	*temp;
	t_node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = NULL;
	last = *b;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *b;
	last->prev = NULL;
	*b = last;
	ft_printf("rrb\n");
}
