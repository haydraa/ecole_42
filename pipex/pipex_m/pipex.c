/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:01 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/12 18:55:50 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_pros(t_data *data, char **argv, char **envp)
{
	dup2(data->end[0], 0);
	dup2(data->outfile, 1);
	ft_close(data);
	close(data->infile);
	close(data->outfile);
	data->path = check_cmd(argv[3], data);
	if (data->path == NULL)
	{
		data->error++;
		return ;
	}
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
	if (data->path == NULL)
	{
		data->error++;
		return ;
	}
	data->cmd_tab = ft_split(argv[2], ' ');
	execve(data->path, data->cmd_tab, envp);
	ultimate_close(data);
}

void	pipex(t_data *data, char **argv, char **envp)
{
	data->error = 0;
	pipe(data->end);
	data->pip1 = fork();
	if (data->pip1 < 0)
		return ;
	if (data->pip1 == 0)
		child1_pros(data, argv, envp);
	data->pip2 = fork();
	if (data->pip2 == 0)
		child2_pros(data, argv, envp);
	//if (data->error != 0)
	//	write(2, "error arg\n", 10);
	ft_close(data);
	waitpid(data->pip1, NULL, 0);
	waitpid(data->pip2, NULL, 0);
}
