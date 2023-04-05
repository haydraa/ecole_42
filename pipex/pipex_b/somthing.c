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

int	ls_forbiden(t_bonus *data, int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (argv[j])
	{
		if (ft_strcmp(argv[j], "") == 0)
			i++;
		j++;
	}
	if (i > 1)
		error_b(data, 4);
	else if (argc != 5 && data->here_doc != 1)
		return (0);
	return (1);
}

void	finish(t_bonus *data, int argc, char **argv, char **envp)
{	
	char	*cmd;
	char	**tab;

	if (ft_strcmp(argv[3], "") == 0 && (ft_strcmp(argv[2], "ls") == 0
			|| ft_strcmp(argv[2], "/usr/bin/ls") == 0
			|| ft_strcmp(argv[2], "/bin/ls") == 0))
	{
		cmd = check_cmd_b(argv[2], data);
		if (cmd == NULL)
			error_cmd(data, argv[2]);
		tab = ft_split(argv[2], ' ');
		dup2(data->outf, 1);
		data->index = -1;
		close(data->inf);
		close(data->outf);
		execve(cmd, tab, envp);
	}	
	if (data->index == -1)
		exit(0);
	else
		check_all_cmd(argv, argc, data);
}

void	check_ls(t_bonus *data, int argc, char **argv, char **envp)
{
	if (ls_forbiden(data, argc, argv) == 1)
	{
		if (ft_strcmp(argv[2], "") == 0 && (ft_strcmp(argv[3], "ls") == 0
				|| ft_strcmp(argv[3], "/usr/bin/ls") == 0
				|| ft_strcmp(argv[3], "/bin/ls") == 0))
		{
			data->path_b = check_cmd_b(argv[3], data);
			if (data->path_b == NULL)
				error_cmd(data, argv[3]);
			data->cmd_tab = ft_split(argv[3], ' ');
			dup2(data->outf, 1);
			data->index = -1;
			execve(data->path_b, data->cmd_tab, envp);
		}
		if (data->index == -1)
		{
			close(data->inf);
			close(data->outf);
			exit(0);
		}
		finish(data, argc, argv, envp);
	}
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
