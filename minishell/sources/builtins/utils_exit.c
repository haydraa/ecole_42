/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:31:35 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/01 12:31:40 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	free_redir_fail_next(t_data *data)
{
	int	i;

	i = -1;
	while (data->data1.arg_tabl[++i])
		free(data->data1.arg_tabl[i]);
	free(data->data1.arg_tabl);
	ft_env_lstclear(&data->env_table);
	close(data->data5.stdin_save);
	close(data->data5.stdout_save);
}

void	ft_continue_exit(t_data *data)
{
	int	len;

	if (data->close_need == 1)
	{
		close(data->data5.stdin_save);
		close(data->data5.stdout_save);
	}
	if (data->data4.nbr_save == 1)
	{
		if (is_number(data->data1.arg_tabl[1]) == 0
			|| ft_atoi(data->data1.arg_tabl[1]) == -2)
		{
			printf("\nnumeric argument required\n");
			free_for_exit(data);
			exit(2);
		}
		len = ft_atoi((data->data1.arg_tabl[1])) % 256;
		free_for_exit(data);
		exit(len);
	}
	printf("\n");
	free_for_exit(data);
	exit(data->data5.last_error);
}

void	free_exit_pipe_next(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->data2.lst_nbr)
		free(data->data3.fds[i]);
	free(data->data3.fds);
}

int	check_for_exit(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (is_number(data->data1.arg_tabl[1]) == 1)
		return (0);
	while (data->data1.arg_tabl[i])
	{
		j++;
		i++;
	}
	if (i <= j)
		return (1);
	else
		return (0);
}
