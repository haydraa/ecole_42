/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:50:11 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/02 15:51:50 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parserror_next(t_data *data)
{
	int	nbr;

	nbr = -1;
	if (data->data3.pcommand != NULL)
		free(data->data3.pcommand);
	data->data3.pcommand = NULL;
	while (data->data4.redir_file[++nbr])
		free(data->data4.redir_file[nbr]);
	free(data->data4.redir_file);
	free(data->data4.redir_type);
	if (data->data3.file != NULL)
		free(data->data3.file);
	close(data->data3.fd);
}

int	parserror2(int nbr, t_data *data)
{
	if (nbr == 1)
	{
		write(2, "syntax error near unexpected token `|'\n", 40);
		data->data5.last_error = 2;
		return (-1);
	}
	if (nbr == 6)
	{
		parserror_next(data);
		return (-1);
	}
	if (nbr == 2)
	{
		ft_lstclear(data, &data->cmd_table);
		write(2, "Error quote not closed\n", 24);
		data->data5.last_error = 1;
		return (-1);
	}
	return (0);
}

void	exekerror_utils(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->data4.nbr_save + 1)
		free(data->data1.arg_tabl[i++]);
	free(data->data1.arg_tabl);
	if (data->hell == 0)
		print_command_not_found(data);
	close(data->data5.stdin_save);
	close(data->data5.stdout_save);
	data->data5.last_error = 127;
}
