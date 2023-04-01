#include "../minishell.h"

void	parsing(t_cmd *data, char **envp)
{
	int x;
	x = 0;
	int i = envlen(envp);
	char **env;
	env = dup_env(envp);
	//idata->cmd_tab = ft_split(data->cmd, ' ');
	printf("%s\n", data->cmd);
	if (ft_strncmp(data->cmd, "env", 3) == 0)
		while (x++ < i - 1)
			printf("%s\n", envp[x]);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	data;
	(void)argc;
	(void)argv;

	while(1)
	{
		data.cmd = readline("minishell$ ");
		parsing(&data, envp);
		add_history(data.cmd);
	}
	return 0;
}

