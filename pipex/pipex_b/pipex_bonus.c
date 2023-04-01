/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:08 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/15 17:33:02 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	creat_pip(t_bonus *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg - 1)
	{
		pipe(data->pip + 2 * i);
		i++;
	}
}

void	check_cmd(t_bonus *data, char **argv)
{
	int		i;
	char	*cmd;

	i = 2 + data->here_doc;
	while (i < data->arg_c - 1)
	{
		cmd = check_cmd_b(argv[i], data);
		if (cmd == NULL)
		{
			free(cmd);
			error_cmd(data, argv[i]);
		}
		free(cmd);
		i++;
	}
}

void	pipex_b(t_bonus *data, char **argv, char **envp)
{
	data->index = -1;
	data->pip = (int *)malloc(sizeof(int) * data->pip_num);
	creat_pip(data);
	//close(data->inf);
	while (++(data->index) < data->num_arg)
		child_b(data, argv, envp);
	waitpid(-1, NULL, 0);
	close_pip(data);
	free(data->pip);
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
			ft_dup2(p->pip[2 * p->index - 2], p->outf);
		else
			ft_dup2(p->pip[2 * p->index - 2], p->pip[2 * p->index + 1]);
		cmd_args = ft_split(argv[2 + p->here_doc + p->index], ' ');
		cmd = check_cmd_b(argv[2 + p->here_doc + p->index], p);
		if (p->here_doc == 1)
			unlink(".hd_tmp");
		close_pip(p);
		close(p->inf);
		close(p->outf);
		execve(cmd, cmd_args, envp);
	}
}
