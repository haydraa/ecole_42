/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/15 17:31:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
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

void check_ls(t_bonus *data, int argc, char **argv, char **envp)
{
	char *cmd;
	char **tab;
	int len;
	len = ft_strlen(argv[4]);
	if (ft_strncmp(argv[3], "", len) == 0 && (ft_strncmp(argv[4], "ls", len) == 0|| ft_strncmp(argv[4],"usr/bin/ls", len) == 0 || ft_strncmp(argv[4], "bin/ls", len) == 0))
	{
		cmd = check_cmd_b(argv[4], data);
		if (cmd == NULL)
			error_cmd(data, argv[4]);
		tab = ft_split(argv[4], ' ');
		dup2(data->outf, 1);
		execve(cmd, tab, envp);
	}
	free(cmd);
	return ; 		
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
