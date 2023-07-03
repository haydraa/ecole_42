/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:28 by cormiere          #+#    #+#             */
/*   Updated: 2023/06/15 16:59:28 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_continue2(t_data *data, char *str)
{
	data->data3.pcommand = ft_strmjoin(data->data3.pcommand, \
	str[data->data3.rdi]);
	if (str[data->data3.rdi] == ' ' && data->data1.squote == 0
		&& data->data1.dquote == 0)
		while (str[data->data3.rdi] == ' ' && data->data1.squote == 0
			&& data->data1.dquote == 0)
			data->data3.rdi++;
	else
		data->data3.rdi++;
}

void	ft_continue3(t_data *data)
{
	data->data3.pcommand = ft_strmjoin(data->data3.pcommand, '\0');
	ft_lstadd_back(&data->cmd_table, ft_lstnew(data->data3.pcommand, \
	data->data4.redir_type, data->data4.redir_file));
	data->data1.here_doc_nbr = data->data1.here_doc_nbr + 1;
}

void	quotes_switch(t_data *data, char *str, int i)
{
	if (str[i] == '\'' && data->data1.dquote == 0)
	{
		if (data->data1.squote == 0)
			data->data1.squote = 1;
		else
			data->data1.squote = 0;
	}
	if (str[i] == '"' && data->data1.squote == 0)
	{
		if (data->data1.dquote == 0)
			data->data1.dquote = 1;
		else
			data->data1.dquote = 0;
	}
}
