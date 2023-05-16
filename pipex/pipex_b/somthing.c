/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 14:07:06 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
}

void	function_of_death(t_bonus *data)
{	
	close_pip(data);
	if (data->outf > 0)
		close(data->outf);
	if (data->inf > 0)
		close(data->inf);
}

int	check(char *cmd)
{
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (!(access(cmd, F_OK)))
			return (1);
	}
	return (0);
}

void	ft_close_std(void)
{
	close(0);
	close(1);
	close(2);
}

void	ft_path_b(t_bonus *data, char **envp)
{
	int	i;

	i = 0;
	data->path_b = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path_b = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!data->path_b)
	{
		data->path_b = ft_calloc(1, sizeof(char));
		data->path_tab_b = ft_split(data->path_b, ':');
		free(data->path_b);
	}
	else
		data->path_tab_b = ft_split(data->path_b, ':');
}
