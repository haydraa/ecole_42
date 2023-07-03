/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalel <jalel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:26 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/24 02:31:07 by jalel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	built_in_two(t_data *data)
{
	if (ft_strncmp(data->data1.arg_tabl[0], "pwd") == 0)
		bin_pwd(data);
	if (ft_strncmp(data->data1.arg_tabl[0], "env") == 0)
		bin_env(data);
	if (ft_strncmp(data->data1.arg_tabl[0], "export") == 0)
	{
		data->data5.last_error = 0;
		bin_export(&data->data1.arg_tabl[1], data);
	}
	if (ft_strncmp(data->data1.arg_tabl[0], "unset") == 0)
		bin_unset(&data->data1.arg_tabl[1], data);
	if (ft_strncmp(data->data1.arg_tabl[0], "echo") == 0)
		bin_echo(data);
	if (ft_strncmp(data->data1.arg_tabl[0], "cd") == 0)
		bin_cd(data);
}

int	built_in(t_data *data, char **env, int nbr)
{
	int	i;

	data->data4.is_built_in = 1;
	if (cmd_redir(data, env, nbr) == -1)
		return (-1);
	built_in_two(data);
	if (ft_strncmp(data->data1.arg_tabl[0], "exit") == 0)
	{
		data->str_exit = 1;
		bin_exit(data, data->data5.is_pipe);
	}
	i = 0;
	while (i <= data->data4.nbr_save + 1)
		free(data->data1.arg_tabl[i++]);
	free(data->data1.arg_tabl);
	if (data->data5.is_pipe == 0)
	{
		dup2(data->data5.stdin_save, 0);
		dup2(data->data5.stdout_save, 1);
	}
	return (0);
}

void	bin_echo_two(t_data *data)
{
	data->data5.echo_i--;
	data->data5.echo_j = 0;
	while (data->data1.arg_tabl[++data->data5.echo_i])
	{
		if (data->data5.echo_j != 0)
			write(1, " ", 1);
		write(1, data->data1.arg_tabl[data->data5.echo_i],
			ft_strlen(data->data1.arg_tabl[data->data5.echo_i]));
		data->data5.echo_j++;
	}
	if (data->data5.echo_n == 0)
		printf("\n");
}

int	bin_echo(t_data *data)
{
	data->data5.echo_i = 0;
	data->data5.echo_n = 0;
	while (data->data1.arg_tabl[++data->data5.echo_i])
	{
		data->data5.echo_j = 0;
		if (data->data1.arg_tabl[data->data5.echo_i] \
			[data->data5.echo_j++] == '-')
			while (data->data1.arg_tabl[data->data5.echo_i][data->data5.echo_j]
				&& data->data1.arg_tabl[data->data5.echo_i] \
				[data->data5.echo_j] == 'n')
				data->data5.echo_j++;
		if (data->data5.echo_j != 1 && data->data1.arg_tabl[data->data5.echo_i] \
			[data->data5.echo_j] == '\0')
			data->data5.echo_n = 1;
		else
		{
			bin_echo_two(data);
			data->data5.last_error = 0;
			return (0);
		}
	}
	if (data->data5.echo_n == 0)
		printf("\n");
	data->data5.last_error = 0;
	return (0);
}

void	bin_env(t_data *data)
{
	int			i;
	t_env_list	*begin;

	i = 0;
	begin = data->env_table;
	if (data->data1.arg_tabl[1] == NULL)
	{
		while (begin)
		{
			if (begin->value != NULL)
			{
				printf("%s", begin->name);
				printf("=%s\n", begin->value);
			}
			begin = begin->next;
			i++;
		}
		data->data5.last_error = 0;
	}
	else
	{
		data->data5.last_error = 127;
		printf("env: No such file or directory\n");
	}
}
