/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:01 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/23 13:22:06 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_lstadd_back(t_cmd_list **alst, t_cmd_list *new)
{
	t_cmd_list	*begin;
	t_cmd_list	*newelm;

	begin = *alst;
	if (!alst)
		return ;
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	while (begin)
	{
		newelm = begin;
		begin = begin->next;
	}
	newelm->next = new;
}

void	ft_lstadd_front(t_cmd_list **alst, t_cmd_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstclear(t_data *data, t_cmd_list **lst)
{
	t_cmd_list	*nexto;
	int			i;

	if (!lst || data->bsn == 1)
		return ;
	nexto = (*lst)->next;
	free(*lst);
	(*lst) = nexto;
	while (*lst != NULL)
	{
		i = -1;
		nexto = (*lst)->next;
		free((*lst)->cmd);
		free((*lst)->redir_type);
		while ((*lst)->redir_file[++i])
			free((*lst)->redir_file[i]);
		free((*lst)->redir_file);
		free(*lst);
		(*lst) = nexto;
	}
}

int	ft_lstsize(t_cmd_list *lst)
{
	int			nbr;
	t_cmd_list	*begin;

	nbr = 0;
	begin = lst;
	while (begin)
	{
		nbr++;
		begin = begin->next;
	}
	return (nbr);
}

void	init_main(t_data *data)
{
	data->data1.here_doc_nbr = 0;
	data->data1.arg_tabl = NULL;
	data->data3.path = 0;
	data->data1.here = 0;
	data->data3.fds = NULL;
	data->data4.nbr_save = 0;
	data->data5.is_pipe = 0;
	data->data3.houna = 0;
	data->data3.redir_error = 0;
	data->data4.unset = 0;
	data->bsn = 0;
	data->hell = 0;
}
