
#include "../minishell.h"

/*
** unset_env: deletes the specified environment variable from the current environment.
** old_env: the current environment.
** index: the index of the environment variable that needs to be deleted.
** returns the new environment after deleting the specified environment variable.
*/
char	**unset_env(char **old_env, int index)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * (envlen(old_env) - 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	while (old_env[i])
	{
		if (i != index)
		{
			new_env[j] = ft_strdup(old_env[i]);
			j++;
		}
		i++;
	}
	free_env(old_env);
	i--;
	new_env[i] = NULL;
	return (new_env);
}

/*
** handle_unset: the main function for unsetting environment variables.
** inputs: the command line inputs for the unset command.
** data: a structure that contains the current environment and other information.
*/
void	handle_unset(char **inputs, t_data *data)
{
	int	i;
	int	index;

	i = 1;
	while (inputs[i])
	{
		if (check_export(inputs[i]))
		{
			index = var_index(inputs[i], data);
			if (index > 0)
				data->env = unset_env(data->env, index);
			i++;
		}
		else
			return (error_sentence("unset: invalid identifier\n", 1));
	}
}
