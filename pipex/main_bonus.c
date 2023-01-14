#include "pipex.h"

int get_files(t_bonus *data, char *in, char *out)
{
	data->inf= open(in, O_RDONLY);
	if (data->inf < 0)
		return (1);
	data->outf = open(out, O_RDWR | O_TRUNC | O_CREAT, 0000644);
	if (data->outf < 0)
		return (1);
	return 0;
}

void ft_path_b(t_bonus *data, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path_b = envp[i] + 5;
			break;
		}
		i++;
	}
	data->path_tab_b = ft_split(data->path_b, ':');
}

int here_doc(t_bonus *data, char **argv)
{
	int i;
	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[1], "her_doc", 7) == 0)
			return 1;
		i++;
	}
	return 0;
}

void ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
}

char *check_cmd_b(char *cmd, t_bonus *data)
{
	char *slash;
	char *path_ac;
	int i;

	i = -1;
	if (ft_strlen(cmd) == 0)
		error_b(data, 4);
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	data->cmd_tab = ft_split(cmd, ' ');
	while (data->path_tab_b[++i])
	{
		slash = ft_strjoin(data->path_tab_b[i], "/");
		path_ac = ft_strjoin(slash, data->cmd_tab[0]);
		free(slash);
		if (!(access(path_ac,F_OK)))
		{
			ft_free_b(data->cmd_tab);
			return path_ac;
		}
		free(path_ac);
	}
	ft_free_b(data->cmd_tab);
	return (NULL);			
}

int main(int argc, char **argv, char **envp)
{
	t_bonus data;
	
	if (get_files(&data, argv[1], argv[argc - 1]) == 1)
		error_b(&data ,1);
	ft_path_b(&data, envp);
	if (!data.path_tab_b)
		error_b(&data, 2);
	data.here_doc = here_doc(&data, argv);
	data.num_arg = argc - 3 - data.here_doc;
	data.num_pip = 2 * (data.num_arg - 1);
	data.pipe = (int*)malloc(sizeof(int) * data.num_pip);
	if (!data.pipe)
		error_b(&data,3);
	pipex_b(&data, argv, envp);
}
