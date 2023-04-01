
#include "../minishell.h"

/*
 * cd_minus - Changes the current working directory to the value of the "OLDPWD" environment variable.
 * @data: Pointer to the data structure that holds environment variables and other relevant data.
 *
 * Returns: 1 if successful, 0 if the "OLDPWD" variable is undefined or the chdir() call fails.
 */
int		cd_minus(t_data *data)
{
	// Check if the "OLDPWD" environment variable is present
	if (var_index("OLDPWD=", data) < 0)
		return (0);

	// Try to change the working directory to the value of "OLDPWD"
	if (chdir((strchr(data->env[var_index("OLDPWD=", data)], '=') + 1)) == -1)
		return (0);

	// If successful, update the current working directory in the environment variables
	change_pwd(data, NULL);

	return (1);
}

/*
 * cd_alone - Changes the current working directory to the value of the "HOME" environment variable.
 * @data: Pointer to the data structure that holds environment variables and other relevant data.
 *
 * Returns: 1 if successful, 0 if the "HOME" variable is undefined or the chdir() call fails.
 */
int		cd_alone(t_data *data)
{
	// Check if the "HOME" environment variable is present
	if (var_index("HOME=", data) < 0)
		return (0);

	// Try to change the working directory to the value of "HOME"
	if (chdir((strchr(data->env[var_index("HOME=", data)], '=') + 1)) == -1)
		return (0);

	// If successful, update the current working directory in the environment variables
	change_pwd(data, NULL);

	return (1);
}

/*
 * handle_cd: handles the cd command
 *
 * @args: array of arguments passed to the cd command
 * @data: struct containing the environment variables
 *
 * This function checks if there are too many arguments passed to the cd command
 * and if not, it changes the directory to either the home directory, the previous
 * directory, or a specified directory. If the directory change is not successful,
 * an error message is printed.
 */
void	handle_cd(char **args, t_data *data)
{
	// If there are more than two arguments, print error message
	if (args[1] && args[2])
		return (error_sentence("cd: too many arguments\n", 1));
	// If there is no argument, change directory to the home directory
	else if (!args[1])
	{
		if (!cd_alone(data))
			return (error_sentence("cd: HOME: is undefined\n", 1));
	}
	// If argument is "-", change directory to the previous directory
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!cd_minus(data))
			return (error_sentence("cd: OLDPWD is undefined\n", 1));
	}
	// If argument is a directory path, change directory to the specified directory
	else
	{
		//if (!cd_path(args, data))
			return (error_sentence("cd: no such file or directory\n", 1));
	}
	// Set the global status to 0
	//g_status = 0;
}
