/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:21:38 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/11 19:31:29 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_node(t_node **lst, int data)
{
	t_node	*temp;
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->next = NULL;
	if (*lst == NULL)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

t_node	**send_to_a(int len, t_data *data)
{
	t_node	**head;
	int		i;

	i = 0;
	head = malloc(sizeof(t_node *));
	if (!head)
		return (NULL);
	*head = NULL;
	while (i < len)
	{
		ft_lstadd_back_node(head, ft_atol(data->all_final[i]));
		i++;
	}
	return (head);
}
