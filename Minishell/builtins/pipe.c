#include "../minishell.h"

void	handle_parentps(char *input2, t_data *data, int pid, int *fds)
{
	int		oldfd;
	int		status;

	if (waitpid(pid, &status, 0) != pid)
		exit(EXIT_FAILURE);
	//free(g_user_input);
	//g_user_input = NULL;
	oldfd = dup(0);
	dup2(fds[0], 0);
	close(fds[0]);
	close(fds[1]);
	//parser_start(input2, data);
	(void)input2;
	(void)data;
	dup2(oldfd, 0);
	close(oldfd);
}

int		handle_pipe(char *input1, char *input2, t_data *data)
{
	pid_t	pid;
	int		fds[2];

	if (pipe(fds) < 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		free(input2);
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		//handle_basic(input1, data, 1);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		free(input1);
		input1 = NULL;
		handle_parentps(input2, data, pid, fds);
	}
	return (1);
}
