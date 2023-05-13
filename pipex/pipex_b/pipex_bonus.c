/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:08 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/13 16:10:58 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_hd_fd(t_bonus *data)
{
	data->inf = open(".hd_tmp", O_RDONLY);
	if (data->inf < 0)
	{
		unlink(".hd_tmp");
		error_b(data, 1);
	}
}

void	here_doc(char *argv, t_bonus *data)
{
	char	*trim;

	data->inf = open(".hd_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (data->inf < 0)
		error_b(data, 1);
	while (1)
	{
		write(1, "heredoc>", 9);
		data->line = get_next_line(0);
		if (ft_strcmp(data->line, "\n") != 0)
		{
			trim = ft_strtrim(data->line, "\n");
			if (ft_strcmp(argv, trim) == 0)
				break ;
			free(trim);
		}
		write(data->inf, data->line, (ft_strlen(data->line) - 1));
		write(data->inf, "\n", 1);
		free(data->line);
	}
	free(data->line);
	free(trim);
	close(data->inf);
	open_hd_fd(data);
}

void	pipex_b(t_bonus *data, char **argv, int argc, char **envp)
{
	(void)argc;
	if (!data->path_tab_b)
		error_b(data, 2);
	check_all_cmd(argv, argc, data);
	data->index = -1;
	data->pip = (int *)malloc(sizeof(int) * data->pip_num);
	creat_pip(data);
	while (++(data->index) < data->num_arg)
		child_b(data, argv, envp);
	data->index = 0;
	close_pip(data);
	while (++(data->index) < data->num_arg)
		waitpid(data->pid, NULL, 0);
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
		close_pip(p);
		close(p->inf);
		close(p->outf);
		if (cmd == NULL)
		{
			free_child(p, cmd_args, cmd);
			ft_close_std();
			exit(1);
		}
		execve(cmd, cmd_args, envp);
	}
}
