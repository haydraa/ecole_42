/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:39 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 11:49:41 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	getcmd_and_pipe_two(t_data *data)
{
	data->data3.pid = fork();
	if (data->data3.pid == 0)
	{
		if (data->data3.exec_i != data->data2.lst_nbr - 1)
			dup2(data->data3.fds[data->data3.exec_i][1], STDOUT_FILENO);
		if (data->data3.exec_i != 0)
			dup2(data->data3.fds[data->data3.exec_i - 1][0], STDIN_FILENO);
		while (data->data2.j < data->data2.lst_nbr - 1)
		{
			close(data->data3.fds[data->data2.j][0]);
			close(data->data3.fds[data->data2.j][1]);
			data->data2.j = data->data2.j + 1;
		}
		return (2);
	}
	if (data->cmd_table->next)
		data->cmd_table = data->cmd_table->next;
	if (data->cmd_table->next)
		data->cmd_table = data->cmd_table->next;
	data->data5.last_error = 127;
	data->data3.exec_i++;
	return (0);
}

void	getcmd_and_pipe_three(t_data *data)
{
	if (data->data3.exec_i != data->data2.lst_nbr - 1)
		dup2(data->data3.fds[data->data3.exec_i][1], STDOUT_FILENO);
	if (data->data3.exec_i != 0)
		dup2(data->data3.fds[data->data3.exec_i - 1][0], STDIN_FILENO);
	while (data->data2.j < data->data2.lst_nbr - 1)
	{
		if (data->data2.close_l == 0)
			close(data->data3.fds[data->data2.j][0]);
		close(data->data3.fds[data->data2.j][1]);
		data->data2.j = data->data2.j + 1;
	}
}

int	getcmd_and_pipe(t_data *data, char **env)
{
	int	i;

	if (ft_is_builtin(data, data->data1.arg_tabl[0]) != 0)
		if (put_path(data) == 2)
			return (getcmd_and_pipe_two(data));
	data->data2.j = 0;
	data->data3.pid = fork();
	if (data->data3.pid == 0)
	{
		getcmd_and_pipe_three(data);
		if (ft_is_builtin(data, data->data1.arg_tabl[0]) == 0)
		{
			i = built_in(data, env, data->data4.bin_nbr);
			data->data4.is_built_in = 0;
			ultimate_free(data, i);
			exit (data->data5.last_error);
		}
		else
		{
			if (cmd_redir(data, env, data->data3.exec_i) != 0)
				return (3);
		}
	}
	return (continue_1(data));
}

void	malloc_fds(t_data *data)
{
	while (++data->data3.exec_i <= data->data2.lst_nbr)
	{
		data->data4.fds_malloced = 1;
		data->data3.fds[data->data3.exec_i] = malloc(sizeof(int) * 2);
		if (!data->data3.fds[data->data3.exec_i])
			exit(EXIT_FAILURE);
	}
}

int	exec_cmds_second(t_data *data, char **env)
{
	data->data3.exec_i = -1;
	data->data4.fds_malloced = 0;
	data->data3.fds = malloc(sizeof(int *) * (data->data2.lst_nbr + 1));
	if (!data->data3.fds)
		exit(EXIT_FAILURE);
	malloc_fds(data);
	data->data3.exec_i = 0;
	while (data->data3.exec_i < data->data2.lst_nbr - 1)
		pipe(data->data3.fds[data->data3.exec_i++]);
	data->data3.exec_i = 0;
	while (data->data3.exec_i < data->data2.lst_nbr)
	{
		data->data3.houna = 1;
		data->data1.arg_tabl = get_cmd(data);
		data->data3.error_getcmd = getcmd_and_pipe(data, env);
		if (data->data3.error_getcmd != 0)
			return (data->data3.error_getcmd);
		data->data4.free_i = 0;
		while (data->data4.free_i <= data->data4.nbr_save + 1)
			free(data->data1.arg_tabl[data->data4.free_i++]);
		free(data->data1.arg_tabl);
		data->data1.arg_tabl = NULL;
	}
	data->data3.exec_i = 0;
	return (0);
}
