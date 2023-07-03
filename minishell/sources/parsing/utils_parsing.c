/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:48:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/06/21 09:48:57 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_stupid_quotes(char *str)
{
	int	i;
	int	j;
	int	len;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == 39)
			j++;
		if (str[i] == '"')
			x++;
		i++;
	}
	if ((j % 2 != 0 || x % 2 != 0) && (j == len || x == len
			|| (j + x) == len))
		printf("Error quote not closed\n");
	if (j == len || x == len || (j + x) == len)
		return (1);
	return (0);
}

int	finsh_stupid(t_data *data, char *str, int x, int j)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == '/' || str[i] == ' ')
		i++;
	if (i == len)
		return (1);
	while (str[i])
	{
		if (str[i] == '/')
			x++;
		if (str[i] == '.')
			j++;
		i++;
	}
	if (x + j == len)
	{
		printf("bash: %s: Is a directory\n", str);
		data->data5.last_error = 126;
		return (1);
	}
	return (0);
}

int	print_msg(t_data *data, int key, char *str)
{
	if (key == 1)
	{
		printf("Minisheru: .: filename argument required]\n");
		printf(".: usage: . filename [arguments]\n");
		data->data5.last_error = 2;
		return (1);
	}
	if (key == 2)
	{
		printf("%s: command not found\n", str);
		data->data5.last_error = 127;
		return (1);
	}
	return (0);
}

int	stupid_problem(t_data *data, char *str)
{
	int	i;
	int	j;
	int	x;
	int	len;

	i = 0;
	x = 0;
	j = 0;
	len = ft_strlen(str);
	if (str == NULL)
		return (2);
	if (check_stupid_quotes(str) == 1)
		return (3);
	if (ft_strncmp(str, ".") == 0)
		return (print_msg(data, 1, str));
	while (str[i] == '.')
		i++;
	if (i == len)
		return (print_msg(data, 2, str));
	if (finsh_stupid(data, str, x, j) == 1)
		return (1);
	return (0);
}

int	continue_func(t_data *data)
{
	if (data->data1.arg_tabl[0] == NULL)
	{
		data->hell = 1;
		if (data->cmd_table->redir_file != NULL)
			return (0);
		else
			return (2);
	}
	return (3);
}
