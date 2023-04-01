
#include "../minishell.h"

void	free_env(char **env)
{
	int	i;
	int	env_len;

	i = 0;
	// Get the number of elements in the environment array
	env_len = envlen(env);
	// Free each element in the environment array
	while (i < env_len)
		free(env[i++]);
	// Free the environment array
	free(env);
}

int		envlen(char **env)
{
	int	i;

	i = 0;
	// Count the number of elements in the environment array
	while (env[i])
		i++;
	return (i + 1);
}

char	**dup_env(char **env)
{
	char	**data_env;
	int		i;
	int 	envlen;
	
 	envlen = envlen(env);
	i = 0;
	// Allocate memory for the duplicate environment array
	data_env = malloc(sizeof(char *) * envlen(env));
	if (!data_env)
		exit(EXIT_FAILURE);
	// Duplicate each element in the environment array
	while (env[i])
	{
		data_env[i] = ft_strdup(env[i]);
		i++;
	}
	// Terminate the duplicate environment array with a null pointer
	data_env[i] = 0;
	return (data_env);
}

void	handle_env(char **env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	// Iterate over each element in the environment array
	while (env[i])
	{
		// Check if the current element contains an equals sign
		str = ft_strstr(env[i], "=");
		if (str)
		{
			j = 0;
			// Write the current element to standard output
			while (env[i][j])
			{
				write(1, &env[i][j], 1);
				j++;
			}
			// Write a newline character to standard output
			ft_putchar('\n');
		}
		i++;
	}
	// Set the global variable g_status to 0
	//g_status = 0;
}
