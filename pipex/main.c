#include "pipex.h"

void parent_pros(t_data *data)
{
	return;

}

void child_pros(t_data *data)
{
	dup2(data->file1,STDIN_FILENO);


	return;
}

void pipex(t_data *data)
{
	pipe(data->end);
	data->pip1 = fork();
	if (data->pip1 < 0)
		return;
	if (!(data->pipe) == 0)
		child_pros(data);
	else 
		parent_pros(data);
}

void ft_path(t_data *data, char **argv, char **envp)
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
	if (check_cmd(argv,data) == 1)
					pipex(data);
}

int  check_cmd(char **argv, t_data *data)
{
	char *slash;
	char *acsses;
	int i;
	data->cmd1 = argv[3];
	data->cmd2 = argv[4];
	
	
	i = -1;
 	if (ft_strnstr(data->cmd1, "/",ft_strlen(cmd1)))
	{
		if (ft_strnstr(data->cmd2), "/",ft_strlen(cmd2))
			return 1;
	}
	while (data->paths[++i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash,
	}
	return 0;
					
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
	close(data.file1);
	close(data.file2);
	return 0;
}
