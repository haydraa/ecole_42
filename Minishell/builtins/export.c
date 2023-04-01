
#include "../minishell.h"

/*
** var_index - finds the index of the variable name in the env array
** @name: name of the variable
** @data: structure containing the env array
**
** Return: index of the variable if found, -1 otherwise
*/
int		var_index(char *name, t_data *data)
{
	int		y;
	int		x;

	x = 0;
	while (data->env[x])
	{
		y = 0;
		while (data->env[x][y] && data->env[x][y] == name[y]
		&& name[y] != '\0' && name[y] != '=' &&
		data->env[x][y] != '\0' && data->env[x][y] != '=')
			y++;
		if ((data->env[x][y] == '\0' || data->env[x][y] == '=') &&
		(name[y] == '\0' || name[y] == '='))
			return (x);
		x++;
	}
	return (-1);
}

/*
** replace_var - replaces a variable in the env array with a new value
** @new_var: new value of the variable
** @data: structure containing the env array
** @index: index of the variable in the env array
*/
void	replace_var(char *new_var, t_data *data, int index)
{
	if (ft_strchr(new_var, '='))
	{
		free(data->env[index]);
		data->env[index] = ft_strdup(new_var);
	}
}

/*
** export_env - exports a new variable to the environment
** @old_env: original environment
** @export: new variable to export
**
** Return: updated environment with the exported variable
*/
char	**export_env(char **old_env, char *export)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = malloc(sizeof(char *) * (envlen(old_env) + 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	while (old_env[i])
	{
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	free_env(old_env);
	new_env[i] = ft_strdup(export);
	i++;
	new_env[i] = NULL;
	return (new_env);
}

void	export_alone(t_data *data)
{
	int		i;
	int		j;
	char	**temp_env;
	char	*swap;

	i = 0;
	// create a duplicate of the environment variables
	temp_env = dup_env(data->env);

	// sort the environment variables alphabetically
	while (temp_env[i + 1])
	{
		j = i + 1;
		if (strcmp(temp_env[i], temp_env[j]) > 0)
		{
			swap = temp_env[j];
			temp_env[j] = temp_env[i];
			temp_env[i] = swap;
			i = 0;
		}
		else
			i++;
	}

	// print the sorted environment variables
	print_export(temp_env);

	// free the duplicate environment variables
	free_env(temp_env);
}

void	handle_export(char **inputs, t_data *data)
{
	int	i;
	int	index;

	i = 1;
	if (inputs[i])
	{
		while (inputs[i])
		{
			// get the index of the current environment variable
			index = var_index(inputs[i], data);

			// if the environment variable exists and it is a valid export statement
			if (index >= 0 && check_export(inputs[i]))
				// replace the existing environment variable
				replace_var(inputs[i], data, index);
			else if (check_export(inputs[i]))
			{
				// if it is a new environment variable, add it to the list of environment variables
				data->env = export_env(data->env, inputs[i]);

				// if the new environment variable can't be added, exit the program with failure status
				if (!data->env)
					exit(EXIT_FAILURE);
			}
			else
				// if the export statement is invalid, print an error message and exit
				return (error_sentence("export: bad identifier\n", 1));
			i++;
		}
	}
	else
		// if no arguments are provided, print the sorted environment variables
		export_alone(data);

	// set the global status variable to 0 (success)
	//g_status = 0;
}
