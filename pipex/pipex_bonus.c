#include "pipex.h"

void creat_pipes(t_bonus *data)
{
	int i;
	i = 0;
	while (i < data->num_arg - 1)
	{
		if (pipe(data->pipe + 2 * i) < 0)
			the_end(data);
		i++;
	}
}

void pipex_b(t_bonus *data, char **argv, char **envp)
{
	creat_pipes(data);
	data->index = -1;
	while (++(data->index) < data->num_arg)
		child_b(data, argv, envp);
 	pip_close(data);
	waitpid(-1, NULL,0);
	the_end(data);
}

void child_b(t_bonus *data, char **argv, char **envp)
{
	data->pid = fork();
	char ** cmd_args;
	char *cmd;
	if (!data->pid)
	{
		if (data->index == 0)
			ft_dup2(data->inf, data->pipe[1]);
		else if (data->index == data->num_arg - 1)
			ft_dup2(data->pipe[2 * data->index - 2], data->outf);
		else
			ft_dup2(data->pipe[2 * data->index - 2], data->pipe[2 * data->index + 1]);
	pip_close(data);
		cmd_args = ft_split(argv[2 + data->here_doc + data->index], ' ');
		cmd = check_cmd_b(argv[2 + data->here_doc + data->index], data);
		if (cmd == NULL)
		{
			free(cmd);
			ft_free_b(cmd_args);
			error_cmd(data, argv[2+data->here_doc +data->index]);
		}
	execve(cmd, cmd_args, envp);
	}
}
