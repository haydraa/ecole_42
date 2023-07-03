/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:11:47 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/01 11:11:48 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	continue_1(t_data *data)
{
	if (data->cmd_table->next)
		data->cmd_table = data->cmd_table->next;
	if (data->cmd_table->next)
		data->cmd_table = data->cmd_table->next;
	data->data3.exec_i++;
	return (0);
}

void	ft_continue_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->data2.lst_nbr - 1)
	{
		close(data->data3.fds[i][0]);
		close(data->data3.fds[i][1]);
		i++;
	}
	i = -1;
	while (++i <= data->data2.lst_nbr)
		free(data->data3.fds[i]);
	close(data->data5.stdin_save);
	close(data->data5.stdout_save);
	ft_env_lstclear(&data->env_table);
	ft_env_lstclear(&data->env_table_sorted);
	free(data->data3.fds);
	ft_close_for_fun();
}

void	while_1(t_data *data)
{
	data->data5.ppi++;
	data->data2.full_path[0] = '\0';
	free(data->data2.full_path);
	data->data2.full_path = ft_1ststrjoin(
			data->data1.paths[data->data5.ppi], data->data1.arg_tabl[0]);
}

void	continue_3(t_data *data)
{
	int	i;

	i = -1;
	if (data->data4.fds_malloced == 1)
	{
		while (++i <= data->data2.lst_nbr)
			free(data->data3.fds[i]);
		free(data->data3.fds);
		data->data3.fds = NULL;
	}
	data->data1.arg_tabl = NULL;
	close(data->data5.stdin_save);
	data->data5.last_error = 127;
	close(data->data5.stdout_save);
	ft_close_for_fun();
}

void	ultimate_free(t_data *data, int key)
{
	int	i;

	i = -1;
	ft_lstclear(data, &data->cmd_table_temp);
	free(data->cmd_table_temp);
	i = -1;
	while (data->data1.paths[++i])
		free(data->data1.paths[i]);
	free(data->data1.paths);
	if (key == -1)
	{
		i = -1;
		write(2, "Error with redirections\n", 25);
		while (data->data1.arg_tabl[++i])
			free(data->data1.arg_tabl[i]);
		free(data->data1.arg_tabl);
		data->data1.arg_tabl = NULL;
		data->data5.last_error = 1;
	}
	ft_continue_free(data);
}
