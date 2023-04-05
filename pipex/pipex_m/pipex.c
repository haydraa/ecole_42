/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:01 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/15 17:18:03 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	finish(t_data *data, char **argv, char **envp)
{
	char	*cmd;
	char	**tab;
	int		index;

	index = 0;
	if (ft_strcmp(argv[3], "") == 0 && (ft_strcmp(argv[2], "ls") == 0
			|| ft_strcmp(argv[2], "/usr/bin/ls") == 0
			|| ft_strcmp(argv[2], "/bin/ls") == 0))
	{
		cmd = check_cmd(argv[2], data);
		tab = ft_split(argv[2], ' ');
		dup2(data->outfile, 1);
		index = 1;
		close(data->infile);
		close(data->outfile);
		execve(cmd, tab, envp);
	}
	if (index == 0)
		return ;
	else
		exit(0);
}

void	check_ls(t_data *data, char **argv, char **envp)
{
	int	index;

	index = 0;
	if (ls_forbiden(argv) == 1)
	{
		if (ft_strcmp(argv[2], "") == 0 && (ft_strcmp(argv[3], "ls") == 0
				|| ft_strcmp(argv[3], "/usr/bin/ls") == 0
				|| ft_strcmp(argv[3], "/bin/ls") == 0))
		{
			data->path = check_cmd(argv[3], data);
			data->path_tab = ft_split(argv[3], ' ');
			dup2(data->outfile, 1);
			index = 1;
			close(data->infile);
			close(data->outfile);
			execve(data->path, data->path_tab, envp);
		}
		if (index == 1)
			exit(0);
		else
			finish(data, argv, envp);
	}
	else
		return ;
}

void	child2_pros(t_data *data, char **argv, char **envp)
{
	dup2(data->end[0], 0);
	dup2(data->outfile, 1);
	ft_close(data);
	close(data->infile);
	close(data->outfile);
	data->path = check_cmd(argv[3], data);
	data->cmd_tab = ft_split(argv[3], ' ');
	execve(data->path, data->cmd_tab, envp);
	ultimate_close(data);
}

void	child1_pros(t_data *data, char **argv, char **envp)
{
	dup2(data->end[1], 1);
	dup2(data->infile, 0);
	close(data->infile);
	close(data->outfile);
	ft_close(data);
	data->path = check_cmd(argv[2], data);
	data->cmd_tab = ft_split(argv[2], ' ');
	execve(data->path, data->cmd_tab, envp);
	ultimate_close(data);
}

void	pipex(t_data *data, char **argv, char **envp)
{
	check_ls(data, argv, envp);
	check_m(data, argv);
	pipe(data->end);
	data->pip1 = fork();
	if (data->pip1 < 0)
		return ;
	if (data->pip1 == 0)
		child1_pros(data, argv, envp);
	data->pip2 = fork();
	if (data->pip2 == 0)
		child2_pros(data, argv, envp);
	ft_close(data);
	waitpid(-1, NULL, 0);
}
