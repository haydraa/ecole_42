/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:50:36 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/02 17:48:20 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_handel(t_data *data)
{
	int	i;

	i = -1;
	ft_lstclear(data, &data->cmd_table_temp);
	while (data->data1.paths[++i])
		free(data->data1.paths[i]);
	free(data->data1.paths);
	i = 0;
	while (i < data->data2.lst_nbr - 1)
	{
		close(data->data3.fds[i][0]);
		close(data->data3.fds[i][1]);
		i++;
	}
	i = -1;
	while (data->data1.arg_tabl[++i])
		free(data->data1.arg_tabl[i]);
	free(data->data1.arg_tabl);
	error_handel_tow(data);
}

void	exekerror3(t_data *data)
{
	int	i;

	handle_directory_error(data);
	i = -1;
	while (data->data4.redir_file[++i])
	{
		if (access(data->data4.redir_file[i], F_OK) != 0)
		{
			write(2, "minishell: ", 12);
			write(2, data->data4.redir_file[i],
				ft_strlen(data->data4.redir_file[i]));
			write(2, ": No such file or directory\n", 28);
		}
		else if (access(data->data4.redir_file[i], R_OK) != 0)
		{
			write(2, "minishell: ", 12);
			write(2, data->data4.redir_file[i],
				ft_strlen(data->data4.redir_file[i]));
			write(2, ": Permission denied\n", 20);
		}
	}
	execkerror_utils(data);
	data->data5.last_error = 127;
}

void	continue_9(t_data *data, int i)
{
	if (data->data5.is_pipe == 1)
	{
		error_handel(data);
		exit(data->data5.last_error);
	}
	else
	{
		i = -1;
		if (data->data1.arg_tabl != NULL)
		{
			if (data->data3.redir_error == 1 && data->data5.is_pipe == 0)
			{
				free_if_execv_fail(data);
				exit(data->data5.last_error);
			}
			else
				free_continue_9(data);
		}
	}
}

void	exekerror2(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd_table->redir_file[++i])
	{
		if (access(data->cmd_table->redir_file[i], F_OK) != 0)
		{
			write(2, "minishell: ", 12);
			write(2, data->cmd_table->redir_file[i],
				ft_strlen(data->cmd_table->redir_file[i]));
			write(2, ": No such file or directory\n", 28);
		}
		else if (access(data->cmd_table->redir_file[i], R_OK) != 0)
		{
			write(2, "minishell: ", 12);
			write(2, data->cmd_table->redir_file[i],
				ft_strlen(data->cmd_table->redir_file[i]));
			write(2, ": Permission denied\n", 20);
		}
		data->data3.houna = 0;
	}
	continue_9(data, i);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
