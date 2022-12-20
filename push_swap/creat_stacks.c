/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:46:47 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:46:49 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_node(t_node **list, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = (*list);
	new->prev = NULL;
	if ((*list) != NULL)
		(*list)->prev = new;
	(*list) = new;
}

t_node **send_to_a(int argc, char **args)
{
	t_node 	**head;
	int i;
		
	i = 0;
	head = malloc(sizeof(t_node*));
	*head = NULL;
	while (i < argc)
	{
		ft_lstadd_back_node(head, ft_atoi(args[i]));
		i++;
	}
	return (head);
}

void	ft_lstadd_back_node(t_node **lst, int data)
{
	t_node	*temp;
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = NULL;
	if (*lst == NULL)
	{
		new->prev = NULL;
		*lst = new;
		return;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

