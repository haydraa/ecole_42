/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:08 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 18:22:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
	//close(one);
	//close(two);
}

void	here_doc(char *argv, t_bonus *data)
{
	int		file;
	char	*line;
	file = open(".hd_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		error_b(data, 1);
	while (1)
	{
		write(1, "heredoc>", 9);
		line = get_next_line(0);
		if (ft_strncmp(argv, line, ft_strlen(argv)) == 0)
			break ;
		write(file, line, ft_strlen(line));
		write(file, "\n", 1);
		free(line);
	}
	free(line);
	close(file);
	data->inf = open(".hd_tmp", O_RDONLY);
	if (data->inf < 0)
	{
		unlink(".hd_tmp");
		error_b(data, 1);
	}
	close(data->inf);
}

void	close_pip(t_bonus *data)
{
	close(data->pip[0]);
	close(data->pip[1]);
	close(data->inf);
	close(data->outf);
}

void	pipex_b(t_bonus *data, char **argv, char **envp)
{
	data->index = -1;
	pipe(data->pip);
//	pipe(data->pip2);
	//if (!data->pip)
	//	error_b(data,3);
	while (++(data->index) < data->num_arg)
	{
		child_b(data, argv, envp);
	}
	waitpid(-1, NULL, 0);
	close_pip(data);
	//close(0);
	data->index = 2;
	the_end(data);
}

void	child_b(t_bonus *p, char **argv, char **envp)
{
	char	**cmd_args;
	char	*cmd;

	p->pid = fork();
	if (!p->pid)
	{
		if (p->index == 0)
			ft_dup2(p->inf, p->pip[1]);
		else if (p->index == p->num_arg - 1)
			ft_dup2(p->pip[0], p->outf);
		else
			ft_dup2(p->pip[0], p->pip[1]);
		close_pip(p);
		cmd_args = ft_split(argv[2 + p->here_doc + p->index], ' ');
		cmd = check_cmd_b(argv[2 + p->here_doc + p->index], p);
		if (cmd == NULL)
		{
			free(cmd);
			ft_free_b(cmd_args);
			error_cmd(p, argv[2 + p->here_doc + p->index]);
	//		close_pip(p);
//			close(p->inf);
//			close(p->outf);
			exit(EXIT_FAILURE);
		}
		execve(cmd, cmd_args, envp);
	}
}
