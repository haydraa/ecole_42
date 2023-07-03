/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:19 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/29 15:21:23 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redir_parsing2(t_data *data, char *str)
{
	data->data2.rdj = data->data3.rdi;
	if (str[data->data2.rdj] == '>' && str[data->data2.rdj + 1] == '>')
	{
		data->data4.redir_type[data->data1.r_tabl] = 1;
		data->data2.rdj++;
	}
	else if (str[data->data2.rdj] == '>')
		data->data4.redir_type[data->data1.r_tabl] = 2;
	else if (str[data->data2.rdj] == '<' && str[data->data2.rdj + 1] == '<')
	{
		data->data4.redir_type[data->data1.r_tabl] = 3;
		data->data2.rdj++;
	}
	else if (str[data->data2.rdj] == '<')
		data->data4.redir_type[data->data1.r_tabl] = 4;
	data->data2.rdj++;
	while (str[data->data2.rdj] == ' ')
		data->data2.rdj++;
	return (0);
}

int	continue_4(char *str, t_data *data)
{
	data->data1.r_tabl = data->data1.r_tabl + 1;
	while (str[data->data2.rdj] == ' ')
		data->data2.rdj++;
	return (data->data2.rdj - data->data3.rdi);
}

int	redir_parsing(char *str, t_data *data)
{
	data->data4.rd_error = redir_parsing2(data, str);
	if (data->data4.rd_error != 0)
		return (data->data4.rd_error);
	while (str[data->data2.rdj])
	{
		quotes_switch(data, str, data->data2.rdj);
		if ((str[data->data2.rdj] == ' ' || str[data->data2.rdj] == '<'
				|| str[data->data2.rdj] == '>') && data->data1.squote == 0
			&& data->data1.dquote == 0)
			break ;
		if (ft_is_chr(str[data->data2.rdj], data) == 1)
			return (-2);
		data->data4.redir_file[data->data1.r_tabl] = ft_strmjoin(data->data4. \
		redir_file[data->data1.r_tabl], str[data->data2.rdj]);
		data->data2.rdj++;
	}
	if (!(data->data4.redir_file[data->data1.r_tabl]))
		return (-2);
	data->data4.redir_file = rm_quote(data->data4.redir_file, data);
	if (str[data->data3.rdi] == '<' && str[data->data3.rdi + 1] == '<')
		if (here_doc_fct(data, data->data4.redir_file[data->data1.r_tabl]) == 6)
			return (6);
	return (continue_4(str, data));
}

int	count_redir(char *str, t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		quotes_switch(data, str, i);
		if ((str[i] == '>' || str[i] == '<') && data->data1.squote == 0
			&& data->data1.dquote == 0)
		{
			if (str[i] == '>' && str[i + 1] == '>')
				i++;
			if (str[i] == '<' && str[i + 1] == '<')
				i++;
			if (str[i] == '>' && str[i + 1] == '<')
				return (-1);
			if (str[i] == '<' && str[i + 1] == '>')
				return (-1);
			count++;
			if (str[i + 1] == '>' && str[i + 1] == '<')
				return (-1);
		}
	}
	return (count);
}
