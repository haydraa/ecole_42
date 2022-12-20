/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:47:11 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:47:14 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_node **node)
{
		if (*node == NULL || (*node)->next == NULL)
				return ;
		t_node *first;
		t_node *last;
		
		first = *node;
		last = *node;
		while (last->next != NULL)
			last = last->next;
		*node = first->next;
		first->next = NULL;
		last->next = first;
		first->prev = last;
		ft_printf("ra\n");
}

void rb(t_node **node)
{
		if (*node == NULL || (*node)->next == NULL)
				return ;
		t_node	*first;
		t_node	*last;

		first = *node;
		last = *node;
		while (last->next != NULL)
				last = last->next;
		*node = first->next;
		first->next = NULL;
		last->next = first;
		first->prev = last;
		ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void rra(t_node **node)
{
		if (*node == NULL || (*node)->next == NULL)
				return ;
		t_node	*temp;
		t_node	*last;

		temp = NULL;
		last = *node;
		while (last->next != NULL)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *node;
		last->prev = NULL;
		*node = last;
		ft_printf("rra\n");
}

void rrb(t_node **node)
{
		if (*node == NULL || (*node)->next == NULL)
				return ;
		t_node	*temp;
		t_node	*last;

		temp = NULL;
		last = *node;
		while (last->next != NULL)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *node;
		last->prev = NULL;
		*node = last;
		ft_printf("rrb\n");
}
