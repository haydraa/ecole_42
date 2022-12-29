#include "pipex.h"

/*void parent_pros(t_data *data)
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
}*/

void display(t_data *data)
{
			int i;
			int j;

			i = 0;
			while (data->path_tab[i] != NULL)
			{
					ft_printf("%s\n", data->path_tab[i]);
					i++;
			}
}

void ft_path(t_data *data, char **argv, char **envp)
{
	int i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=",5) == 0)
		{
			data->path = envp[i] + 5;
			break ;
		}
		i++;	
	}
	data->path_tab = ft_split(data->path,':');
}

char *check_cmd(char *cmd, t_data *data)
{
	char *slash;
	char *path_ac;
	int i;
	
	i = -1;
	while (data->path_tab[++i])
	{
		slash = ft_strjoin(data->path_tab[i], "/");
		path_ac = ft_strjoin(slash,cmd);
		free(slash);
		if (!(access(path_ac,F_OK)))
				return path_ac;
		free(path_ac);
	}
	return (NULL);					
}

int main(int argc,char **argv, char **envp)
{
	t_data data;
	data.file1 = open(argv[1], O_RDONLY);
	if (data.file1 == -1)
		return 0;
	data.file2 = open(argv[argc -1], O_RDONLY);
	if (data.file2 == -1)
		return 0;
	ft_printf("%s\n" ,argv[2]);
	ft_path(&data,argv,envp);
//	data.path = check_cmd(argv[2],&data);
	close(data.file1);
	close(data.file2);
	return 0;
}
