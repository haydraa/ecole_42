/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:11:29 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/01 11:11:34 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_if_cmd_fail(t_data *data)
{
	int	i;

	ft_lstclear(data, &data->cmd_table_temp);
	ft_env_lstclear(&data->env_table);
	ft_env_lstclear(&data->env_table_sorted);
	i = -1;
	while (data->data1.paths[++i])
		free(data->data1.paths[i]);
	free(data->data1.paths);
	i = -1;
	while (data->data1.arg_tabl[++i])
		free(data->data1.arg_tabl[i]);
	free(data->data1.arg_tabl);
	i = -1;
	if (data->data3.fds != NULL)
	{
		while (++i <= data->data2.lst_nbr)
			free(data->data3.fds[i]);
		free(data->data3.fds);
	}
	data->data1.arg_tabl = NULL;
	close(data->data5.stdin_save);
	data->data5.last_error = 127;
	close(data->data5.stdout_save);
	ft_close_for_fun();
}
