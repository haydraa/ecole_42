/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:27 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/13 15:07:04 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *cmd)
{
	write(2, "bash: ", 6);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
}

void	ft_error_args(void)
{	
	write(2, "ERROR_ARGS\n", 12);
	exit(0);
}

void	ft_close_std(void)
{
	close(0);
	close(1);
	close(2);
}

void	ultimate_close(t_data *data)
{
	close(data->end[0]);
	close(data->end[1]);
	free(data->path);
	exit(EXIT_FAILURE);
}

void	ft_free(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
