/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:49 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:10 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env_list	*ft_env_lstnew(char *name, char *value)
{
	t_env_list	*newelm;

	newelm = (t_env_list *)malloc(sizeof(t_env_list));
	if (!newelm)
		return (0);
	newelm->name = name;
	newelm->value = value;
	newelm->next = NULL;
	return (newelm);
}

void	ft_env_lstclear(t_env_list **lst)
{
	t_env_list	*nexto;

	while (*lst)
	{
		nexto = (*lst)->next;
		free((*lst)->name);
		free((*lst)->value);
		free(*lst);
		(*lst) = nexto;
	}
}
