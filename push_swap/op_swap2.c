/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:49:09 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:49:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_node **a, t_node **b)
{
		int i;
		t_node *temp;

		temp = *b;
		i = temp->data;
		(*b) = (*b)->next;
		ft_lstadd_front_node(a, i);
//		free(temp);
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
		t_node *temp;
		int i;

		temp = *a;
		i = temp->data;
		*a = (*a)->next;
		ft_lstadd_front_node(b,i);
//		free(temp);
		ft_printf("pb\n");
}

void rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
