/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:26:26 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 17:50:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_chr(char c, t_data *data)
{
	if ((c == 33 || c == 35 || c == 42 || c == 40 || c == 41
			|| c == 59 || c == 63 || c == 124)
		&& data->data1.squote == 0 && data->data1.dquote == 0)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (nmemb == 0 || size <= 0)
		return (malloc(0));
	if (!(nmemb * size / size == nmemb))
		return (NULL);
	dest = malloc(size * nmemb);
	if (dest == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	check_rl(void)
{
	if (g_data->sigint == 1)
		rl_done = 1;
	return (0);
}

int	main_utils(t_data *data)
{
	int	i;

	if (ft_strncmp(data->main_str, "") == 0)
	{
		data->data3.main_error = 0;
		data->data5.last_error = 127;
		data->bsn = 1;
		return (1);
	}
	i = stupid_problem(data, data->main_str);
	if (i == 1)
	{
		data->data3.main_error = 0;
		add_history(data->main_str);
		data->data5.last_error = 127;
		data->bsn = 1;
		return (1);
	}
	return (main_utils_2(data, i));
}

void	free_fds_error(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->data2.lst_nbr - 1)
	{
		close(data->data3.fds[i][0]);
		close(data->data3.fds[i][1]);
		i++;
	}
	close(0);
	close(1);
	close(2);
	i = -1;
	while (++i <= data->data2.lst_nbr)
		free(data->data3.fds[i]);
}
