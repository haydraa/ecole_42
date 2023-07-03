/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalel <jalel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:30 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 11:41:33 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**recup_path(t_data *data)
{
	int		i;
	char	*str;
	char	**tabl;

	str = ft_found_path(data, "PATH");
	i = -1;
	data->data2.nbr = 0;
	while (str && str[++i])
		if (str[i] == ':')
			data->data2.nbr = data->data2.nbr + 1;
	data->data1.path_nbr = data->data2.nbr;
	tabl = malloc(sizeof(char *) * (data->data2.nbr + 2));
	tabl[data->data2.nbr + 1] = NULL;
	while (i-- > 0)
	{
		if (str[i] == ':')
		{
			tabl[data->data2.nbr] = ft_malloc_str(&str[i + 1]);
			str[i] = '\0';
			data->data2.nbr = data->data2.nbr - 1;
		}
	}
	tabl[data->data2.nbr] = ft_malloc_str(str);
	free(str);
	return (tabl);
}

void	wait_loop(t_data *data)
{
	int	error_code;
	int	status;

	error_code = 0;
	status = wait(&data->data5.last_error);
	while (status != -1)
	{
		if (WIFEXITED(data->data5.last_error))
		{
			error_code = WEXITSTATUS(data->data5.last_error);
		}
		else if (WIFSIGNALED(data->data5.last_error))
		{
			error_code = WTERMSIG(data->data5.last_error) + 128;
		}
		status = wait(&data->data5.last_error);
	}
	data->data5.last_error = error_code;
}

char	*safe_malloc(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		exit(EXIT_FAILURE);
	return (str);
}

int	ft_continue(t_data *data)
{
	free(data->data1.arg_tabl[0]);
	data->data1.arg_tabl[0] = ft_malloc_str(data->data2.full_path);
	free(data->data2.full_path);
	return (0);
}

int	put_path(t_data *data)
{
	data->data5.ppi = -1;
	data->data4.set = continue_func(data);
	if (data->data4.set == 0)
		return (0);
	else if (data->data4.set == 2)
		return (2);
	if (access(data->data1.arg_tabl[0], X_OK) == 0)
	{
		data->data5.last_error = 126;
		return (0);
	}
	data->data2.full_path = safe_malloc();
	data->data2.full_path[0] = '\0';
	while (access(data->data2.full_path, X_OK) == -1
		&& data->data5.ppi < data->data1.path_nbr)
		while_1(data);
	data->data5.ppi = 0;
	if (access(data->data2.full_path, X_OK) == 0)
		return (ft_continue(data));
	else
		free(data->data2.full_path);
	return (2);
}
