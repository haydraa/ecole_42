#include "pipex.h"

/*
void parent_pros(t_data *data)
{
	return;
}

void child_pros(t_data *data)
{
	return;
}
*/
void pipex(t_data *data)
{
	int end[2];
	pipe(end);
	data->pip1 = fork();
	if (data->pip1 < 0)
		return;
	if (!(data->pipe) == 0)
		child_pros(data);
	else 
		parent_pros(data);
}

void ft_path(t_data *data, char **envp)
{
	int i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=",5) == 0)
		{
			data->path = envp[i];
			return ;
		}
		i++;			
	}
	data->path_tab = ft_split(data->path,":");
}

void find_cmd(char **argv, t_data *data, char **envp)
{
	int i;
	
	i = 1;
	while ()
}

int main(int argc,char **argv, char **envp)
{
	t_data data;
	data.file1 = open(argv[1] , O_RDONLY)
	if (data.file1 == -1)
		return 0;
	data.file2 = open(argv[1], O_RDWR);
	if (data.file2 == -1)
		return 0;
	find_cmd(argv,&data,envp);
	pipex(&data);
	close(data.file1);
	close(data.file2);
	return 0;
}
