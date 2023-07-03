/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:35 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 17:38:15 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	forward_redir(t_data *data, int i)
{
	int	file;

	file = 0;
	if (data->cmd_table->redir_type[i] == 1)
	{
		file = open(data->cmd_table->redir_file[i],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		if (file < 0)
			return (-1);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	if (data->cmd_table->redir_type[i] == 2)
	{
		file = open(data->cmd_table->redir_file[i],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (file < 0)
			return (-1);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	return (0);
}

int	backward_redir(t_data *data, int i, int nbr)
{
	int		file;
	char	*here_doc_file;

	file = 0;
	if (data->cmd_table->redir_type[i] == 3)
	{
		here_doc_file = ft_strjoin_c("/tmp/.here_doc", (char)(nbr + 97));
		file = open(here_doc_file, O_RDONLY);
		if (file < 0)
			return (-1);
		dup2(file, STDIN_FILENO);
		close(file);
		free(here_doc_file);
	}
	if (data->cmd_table->redir_type[i] == 4)
	{
		file = open(data->cmd_table->redir_file[i], O_RDONLY);
		if (file < 0)
			return (-1);
		dup2(file, STDIN_FILENO);
		close(file);
	}
	return (0);
}

int	cmd_redir(t_data *data, char **env, int nbr)
{
	int		i;

	i = -1;
	while (data->cmd_table->redir_type[++i] != 0)
		if (while_redir(data, i, nbr) == -1)
			return (-1);
	if (data->data4.is_built_in == 0)
	{
		data->data5.finale = 0;
		if (data->cmd_table->cmd == NULL)
		{
			free_if_cmd_fail(data);
			exit(data->data5.last_error);
		}
		if (data->cmd_table->cmd[0] == '\0')
		{
			data->data5.finale = 1;
			free_if_cmd_fail(data);
			exit (data->data5.last_error);
		}
		execve(data->data1.arg_tabl[0], data->data1.arg_tabl, env);
		free_if_execv_fail(data);
		exit(data->data5.last_error);
	}
	return (0);
}

int	exec_cmds(t_data *data, char **env)
{
	char	*hd_file;

	data->data3.error_getcmd = exec_cmds_second(data, env);
	if (data->data3.error_getcmd != 0)
		return (data->data3.error_getcmd);
	exec_cmds_two(data);
	wait_loop(data);
	data->data3.exec_i = 0;
	while (data->data3.exec_i < data->data2.lst_nbr)
	{
		hd_file = ft_strjoin_c("/tmp/.here_doc", \
		(char)(data->data3.exec_i + 97));
		if (access(hd_file, F_OK) == 0)
			unlink(hd_file);
		free(hd_file);
		data->data3.exec_i++;
	}
	data->data4.free_i = -1;
	while (++data->data4.free_i <= data->data2.lst_nbr)
		free(data->data3.fds[data->data4.free_i]);
	free(data->data3.fds);
	return (0);
}

int	ft_execution(t_data *data, char **env)
{
	t_cmd_list	*last;

	last = ft_lstlast(data->cmd_table);
	data->data2.lst_nbr = ft_lstsize(data->cmd_table);
	close_hell(data);
	if (data->data2.lst_nbr == 1)
	{
		return (exec_one_cmd(data, env));
	}
	if (data->data2.lst_nbr > 1)
	{
		data->data5.is_pipe = 1;
		if (last->cmd[0] == '\0' && data->data2.rdj == 0)
			return (4);
		data->data2.lst_nbr = (data->data2.lst_nbr / 2) + 1;
		return (exec_cmds(data, env));
	}
	return (0);
}
