/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:20 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 15:20:35 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	suit(t_bonus *data, int key)
{
	if (key == 4)
		error_death(data);
	if (key == 5)
	{
		write(2, "error malloc pid\n", 18);
		ft_free_b(data->path_tab_b);
		exit(1);
	}
	if (key == 6)
	{
		write(2, "error malloc pip\n", 18);
		free(data->pid);
		ft_free_b(data->path_tab_b);
		exit(1);
	}
}

void	error_b(t_bonus *data, int key)
{
	if (key == 0)
	{
		write(2, "Error_args\n", 11);
		exit(1);
	}
	else if (key == 1)
	{
		write(2, "Error_file\n", 11);
		exit(1);
	}
	else if (key == 2)
	{
		write(2, "Error_path\n", 11);
		ft_free_b(data->path_tab_b);
		exit(1);
	}
	else if (key == 3)
	{
		write(2, "Error_pipe\n", 11);
		ft_free_b(data->path_tab_b);
		the_end(data);
	}
	else
		suit(data, key);
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

void	close_pip(t_bonus *data)
{
	int	i;

	i = 0;
	while (i < data->pip_num)
	{
		close(data->pip[i]);
		i++;
	}
}

void	the_end(t_bonus *data)
{
	if (data->here_doc == 1)
	{
		unlink(".hd_tmp");
		ft_free_b(data->path_tab_b);
		close(data->inf);
		if (data->outf > 0)
			close(data->outf);
		close(0);
		close(1);
		close(2);
		exit(0);
	}
	else
	{
		if (data->inf > 0)
			close(data->inf);
		if (data->outf > 0)
			close(data->outf);
		ft_free_b(data->path_tab_b);
		close(0);
		close(1);
		close(2);
		exit(0);
	}
}
