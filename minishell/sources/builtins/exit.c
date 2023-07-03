/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:43 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 17:46:36 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_for_redir_fail(t_data *data)
{
	int	i;

	i = -1;
	free_start(data);
	i = -1;
	while (++i < data->data2.lst_nbr - 1)
	{
		close(data->data3.fds[i][0]);
		close(data->data3.fds[i][1]);
	}
	i = -1;
	if (data->data3.fds != NULL)
	{
		while (++i <= data->data2.lst_nbr)
			free(data->data3.fds[i]);
		free(data->data3.fds);
	}
	free_redir_fail_next(data);
	if (data->data5.is_pipe == 1)
	{
		ft_close_for_fun();
		exit(data->data5.last_error);
	}
}

void	free_for_exit(t_data *data)
{
	int	i;

	i = -1;
	if (data->str_exit == 1)
	{
		if (data->data2.rdj != 0)
		{
			while (data->data4.redir_file[++i])
				free(data->data4.redir_file[i]);
		}
		free(data->data4.redir_file);
		free(data->data4.redir_type);
		free(data->data3.pcommand);
		free(data->cmd_table_temp);
		if (data->data1.arg_tabl != NULL)
		{
			i = -1;
			while (data->data1.arg_tabl[++i])
				free(data->data1.arg_tabl[i]);
			free(data->data1.arg_tabl);
		}
	}
	ft_close_for_fun();
}

void	free_exit_pipe(t_data *data)
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
	free_exit_pipe_next(data);
	i = -1;
	while (data->data1.arg_tabl[++i])
		free(data->data1.arg_tabl[i]);
	free(data->data1.arg_tabl);
	ft_env_lstclear(&data->env_table);
	close(data->data5.stdin_save);
	close(data->data5.stdout_save);
	ft_close_for_fun();
}

void	free_exit_argument(t_data *data)
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
	data->data1.arg_tabl = NULL;
	ft_env_lstclear(&data->env_table);
	close(data->data5.stdin_save);
	close(data->data5.stdout_save);
	ft_close_for_fun();
}

void	bin_exit(t_data *data, int is_pipe)
{
	int	i;

	i = -1;
	if (data->data2.lst_nbr > 1)
	{
		if (is_pipe == 1)
			bin_exit_next(data, 1);
	}
	if (data->data4.nbr_save > 1)
	{
		printf("exit: too many arguments\n");
		if (is_number(data->data1.arg_tabl[1]) == 0)
		{
			free_exit_argument(data);
			exit(2);
		}
	}
	if (!(data->data4.nbr_save > 1))
	{
		if (is_pipe == 0)
			printf("exit");
		while (data->data1.paths[++i])
			free(data->data1.paths[i]);
		bin_exit_next(data, 2);
	}
}
