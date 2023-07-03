/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:36 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/25 11:31:20 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setup_term(int save)
{
	struct termios			t;
	static int				ifsave;
	static struct termios	saved;

	if (!ifsave)
	{
		tcgetattr(STDOUT_FILENO, &saved);
		ifsave = 1;
	}
	tcgetattr(STDOUT_FILENO, &t);
	t.c_lflag &= ~ECHOCTL;
	t.c_cc[VQUIT] = 0;
	if (save == 1)
		tcsetattr(STDOUT_FILENO, TCSANOW, &saved);
	else
		tcsetattr(STDOUT_FILENO, TCSANOW, &t);
}

int	str_is_empty(char *str)
{
	if (str[0])
		return (1);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = -1;
	while (data->data1.paths[++i])
		free(data->data1.paths[i]);
	free(data->data1.paths);
	if (data->close_need == 1)
	{
		close(data->data5.stdin_save);
		close(data->data5.stdout_save);
	}
	free(data->main_str);
}

void	exec_cmds_two(t_data *data)
{
	while (data->data3.exec_i < data->data2.lst_nbr - 1)
	{
		close(data->data3.fds[data->data3.exec_i][0]);
		close(data->data3.fds[data->data3.exec_i][1]);
		data->data3.exec_i++;
	}
	data->data3.exec_i = 0;
}
