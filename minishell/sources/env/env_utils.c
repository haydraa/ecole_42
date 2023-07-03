/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:40 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:06 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env_lstadd_back(t_env_list **lst, t_env_list *new)
{
	t_env_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new != NULL)
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return ;
}

void	ft_env_lstadd_front(t_env_list **alst, t_env_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_env_list	*ft_env_lstlast(t_env_list *lst)
{
	t_env_list	*last;
	t_env_list	*begin;

	begin = lst;
	if (begin == 0)
		return (0);
	while (begin)
	{
		last = begin;
		begin = begin->next;
	}
	return (last);
}

int	ft_env_lstsize(t_env_list *lst)
{
	int			nbr;
	t_env_list	*begin;

	nbr = 0;
	begin = lst;
	while (begin)
	{
		nbr++;
		begin = begin->next;
	}
	return (nbr);
}
