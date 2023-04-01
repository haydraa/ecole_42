#include "pipex_bonus.h"

void	error_cmd2(t_bonus *data, char *cmd)
{
	write(2, "bash: ", 6);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	close(data->inf);
	close(data->outf);
	close(0);
	close(1);
	close(2);
	ft_free_b(data->path_tab_b);
	exit(EXIT_FAILURE);
}

void check_all_cmd(char **argv, int argc, t_bonus *data)
{
	int i;
	char *path;
	
	if (data->here_doc == 1)
		i = 4;
	else
		i = 2;
	while (i < argc -1)
	{
		if (ft_strcmp(argv[i], "") == 0)
			error_cmd2(data, argv[i]);
		path = check_cmd_b(argv[i], data);
		if (path == NULL)
			error_cmd2(data, argv[i]);
		free(path);
		i++;
	}
}







