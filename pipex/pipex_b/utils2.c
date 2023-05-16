/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:18:43 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 15:35:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	malloc_pip_pid(t_bonus *data)
{
	data->pid = malloc(sizeof(pid_t) * data->num_arg);
	if (!data->pid)
		error_b(data, 5);
	data->pip = (int *)malloc(sizeof(int) * data->pip_num);
	if (!data->pip)
		error_b(data, 5);
}

void	check_file(t_bonus *data)
{
	close_pip(data);
	if (data->inf > 0)
		close(data->inf);
	if (data->outf > 0)
		close(data->outf);
	free(data->pid);
	ft_close_std();
	free(data->pip);
	ft_free_b(data->path_tab_b);
	exit(1);
}
