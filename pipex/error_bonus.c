/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:20 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 18:21:21 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_b(t_bonus *data, int key)
{
	if (key == 1)
	{
		write(1, "Error_file\n", 11);
		exit(1);
	}
	if (key == 2)
	{
		write(1, "Error_path\n", 11);
		ft_free_b(data->path_tab_b);
		exit(1);
	}
	if (key == 3)
	{
		write(1, "Error_pipe\n", 11);
		ft_free_b(data->path_tab_b);
		the_end(data);
	}
}

void	error_cmd(t_bonus *data, char *cmd)
{
	write(2, "bash: ", 6);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	ft_free_b(data->path_tab_b);
//	close(0);
//	close(1);
//	close(2);
}

void	ft_free_b(char **tab)
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

void	the_end(t_bonus *data)
{
	if (data->here_doc == 1)
	{
		unlink(".hd_tmp");
		close(data->inf);
		close(data->outf);
	}
	close(data->inf);
	close(data->outf);
	ft_free_b(data->path_tab_b);
//	close(0);
//	close(1);
//	close(2);
	exit(1);
}
