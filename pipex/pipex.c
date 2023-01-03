#include "pipex.h"

void parent_pros(t_data *data, char **argv, char **envp)
{
	dup2(data->end[0],0);
	close(data->end[1]);
	dup2(data->outfile,1);
	data->path = check_cmd(argv[3] , data);
	data->cmd_tab = ft_split(argv[3] , ' ') ;
	if (data->path == NULL)
		ft_error(data, argv[3]);
	execve(data->path,data->cmd_tab, envp);
}

void child_pros(t_data *data , char **argv ,char **envp)
{
	dup2(data->end[1],1);
	close(data->end[0]);
	dup2(data->infile,0);
	data->path = check_cmd(argv[2] , data);
	if (data->path == NULL)
		ft_error(data,argv[2]);
	data->cmd_tab = ft_split(argv[2] , ' ');
	execve(data->path,data->cmd_tab, envp);
}

void	ft_close(t_data *data)
{
	close(data->end[0]);
	close(data->end[1]);
}
void pipex(t_data *data , char **argv ,char **envp)
{
	pipe(data->end);
	data->pip1 = fork();
	if (data->pip1 < 0)
		return;
	if (data->pip1 == 0)
		child_pros(data, argv, envp);
	data->pip2 = fork();
	if (data->pip2 == 0)
		parent_pros(data, argv, envp);
	ft_close(data);
	waitpid(data->pip1,NULL,0);
	waitpid(data->pip2,NULL,0);


}
