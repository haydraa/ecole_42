/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:01 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/15 18:04:01 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_pros(t_data *data, char **argv, char **envp)
{
	data->pip2 = fork();
	if (data->pip2 < 0)
		return ;
	if (data->pip2 == 0)
	{
		dup2(data->end[0], 0);
		dup2(data->outfile, 1);
		ft_close(data);
		if (data->infile > 0)
			close(data->infile);
		if (data->outfile > 0)
		close(data->outfile);
		data->path = check_cmd(argv[3], data);
		if (data->path == NULL)
		{
			write(2, "error cmd2\n", 11);
			free(data->path);
			ft_free(data->path_tab);
			ft_close_std();
			exit(1);
		}
		data->cmd_tab = ft_split(argv[3], ' ');
		execve(data->path, data->cmd_tab, envp);
		ultimate_close(data);
	}
}

void	child1_pros(t_data *data, char **argv, char **envp)
{
	data->pip1 = fork();
	if (data->pip1 < 0)
		return ;
	if (data->pip1 == 0)
	{
		dup2(data->end[1], 1);
		dup2(data->infile, 0);
		if (data->infile > 0)
			close(data->infile);
		if (data->outfile > 0)
			close(data->outfile);
		ft_close(data);
		data->path = check_cmd(argv[2], data);
		if (data->path == NULL)
		{
			write(2, "error cm1d\n", 11);
			free(data->path);
			ft_free(data->path_tab);
			ft_close_std();
			exit(1);
		}
		data->cmd_tab = ft_split(argv[2], ' ');
		execve(data->path, data->cmd_tab, envp);
		ultimate_close(data);
	}
}

void	pipex(t_data *data, char **argv, char **envp)
{
	check_m(data, argv);
	pipe(data->end);
	if (data->infile < 0 && data->outfile > 0)
	{
		child2_pros(data, argv, envp);
		ft_close(data);
		waitpid(data->pip2, NULL, 0);
	}		
	else if (data->outfile < 0 && data->infile > 0)
	{
		child1_pros(data, argv, envp);
		ft_close(data);
		waitpid(data->pip1, NULL, 0);
	}
	else
	{
		child1_pros(data, argv, envp);
		child2_pros(data, argv, envp);
		ft_close(data);
		waitpid(data->pip1, NULL, 0);
		waitpid(data->pip2, NULL, 0);
	}
}
