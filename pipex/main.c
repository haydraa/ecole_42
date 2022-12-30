#include "pipex.h"

void parent_pros(int file2, t_data *data, char **argv, char **envp)
{
	dup2(data->end[0],0);
	close(data->end[1]);
	dup2(data->outfile,1);
	data->path = check_cmd(argv[3] , data);
	data->cmd_tab = ft_split(argv[3] , ' ') ;
	execve(data->path,data->cmd_tab, envp);
}

void child_pros(int file1, t_data *data , char **argv ,char **envp)
{
	dup2(data->end[1],1);
	close(data->end[0]);
	dup2(data->infile,0);
	data->path = check_cmd(argv[2] , data);
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
		child_pros(data->infile, data, argv,envp);
	data->pip2 = fork();
	if (data->pip2 == 0)
		parent_pros(data->outfile, data, argv,envp);
	ft_close(data);
	waitpid(data->pip1,NULL,0);
	waitpid(data->pip2,NULL,0);
	
}

void display(char **tab)
{
			int i;
			int j;

			i = 0;
			while (tab[i] != NULL)
			{
					ft_printf("%s\n", tab[i]);
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
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1)
		return 0;
	data.outfile = open(argv[argc -1], O_RDWR | O_TRUNC | O_CREAT);
	if (data.outfile == -1)
		return 0;
//	ft_printf("%s\n" ,argv[2]);
	ft_path(&data,argv,envp);
	pipex(&data,argv ,envp);
//	data.path = check_cmd(argv[2],&data);
	close(data.infile);
	close(data.outfile);
	return 0;
}
