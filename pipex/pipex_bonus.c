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

#include "pipex.h"

void	ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
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
}

void	creat_pipes(t_bonus *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg - 1)
	{
		if (pipe(data->pipe + 2 * i) < 0)
			the_end(data);
		i++;
	}
}

void	pipex_b(t_bonus *data, char **argv, char **envp)
{
//	creat_pipes(data);
	data->index = -1;
	pipe(data->pip);
//	pipe(data->pip1);
	while (++(data->index) < data->num_arg)
	{
		child_b(data, argv, envp);
//		close(data->pip[0]);
	}
//	pip_close(data);
	waitpid(-1, NULL, 0);
	close(data->pip[0]);
	close(data->pip[1]);
	close(data->inf);
	close(data->outf);
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
		if (p->here_doc == 1)
		{
//			close(p->inf);
//			close(0);
		}
		if (p->index == 0)
		{
			ft_dup2(p->inf, p->pip[1]);
//			close(0);
		}
		else if (p->index == p->num_arg - 1)
		{
			ft_dup2(p->pip[0], p->outf);
//			close(0);
		}
		else
		{
			ft_dup2(p->pip[0], p->pip[1]);
			close(p->inf);
		}
		close(p->pip[0]);
		close(p->pip[1]);
//		close(0);
		//close(1);
		//close(2);
		close(p->inf);
		close(p->outf);
		cmd_args = ft_split(argv[2 + p->here_doc + p->index], ' ');
		cmd = check_cmd_b(argv[2 + p->here_doc + p->index], p);
		if (cmd == NULL)
		{
			free(cmd);
			ft_free_b(cmd_args);
			error_cmd(p, argv[2 + p->here_doc + p->index]);
			exit(EXIT_FAILURE);
		}
		execve(cmd, cmd_args, envp);
	}
}
