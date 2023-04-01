
#include "../minishell.h"

void	change_env_pwd(t_data *data)
{
	char *pwd;

	// Get the current working directory
	data->pwd = getcwd(NULL, 0);

	// If "PWD" exists in environment variables
	if (var_index("PWD", data) >= 0)
	{
		// Create a new string "PWD=current_working_directory"
		pwd = ft_strjoin("PWD=", data->pwd);
		// Replace the existing "PWD" environment variable with the new one
		replace_var(pwd, data, var_index(pwd, data));
		// Free the memory used by the new string
		free(pwd);
	}
	// If "PWD" does not exist in environment variables
	else
	{
		// Create a new string "PWD=current_working_directory"
		pwd = ft_strjoin("PWD=", data->pwd);
		// Add the new string to the environment variables
		data->env = export_env(data->env, pwd);
		// Free the memory used by the new string
		free(pwd);
	}
}

void	change_env_oldpwd(t_data *data)
{
	char *pwd;
	char *oldpwd;

	// If "OLDPWD" exists in environment variables
	if (var_index("OLDPWD", data) >= 0)
	{
		// Create a new string "PWD=current_working_directory"
		pwd = ft_strjoin("PWD=", data->pwd);
		// Create a new string "OLD=PWD=current_working_directory"
		oldpwd = ft_strjoin("OLD", pwd);
		// Replace the existing "OLDPWD" environment variable with the new one
		replace_var(oldpwd, data, var_index("OLDPWD=", data));
		// Free the memory used by the new strings
		free(oldpwd);
		free(pwd);
	}
	// If "OLDPWD" does not exist in environment variables
	else
		// Add "OLDPWD" to the environment variables
		data->env = export_env(data->env, "OLDPWD");
	// Free the memory used by current working directory
	free(data->pwd);
}

/*
 * This function changes the current working directory, updates the
 * environment variables PWD and OLDPWD and frees memory.
 *
 * Input:
 *  t_data *data - a pointer to a structure that holds information about
 *                 environment variables and other data
 *  char *input - a string representing the input (directory to change to)
 *
 * Output:
 *  Returns 1 if the function was able to successfully change the directory
 *  and update the environment variables.
 */
int		change_pwd(t_data *data, char *input)
{
	char	*pwd;
	char	*cwd;

	// Get the current working directory and store it in 'cwd'
	cwd = getcwd(NULL, 0);

	// If 'cwd' is NULL and input is ".", print error message
	if (!cwd && input && ft_strcmp(".", input) == 0)
	{
		ft_putstr_fd("Error retrieving current directory\n", 2);

		// Join the old value of data->pwd with "/." and store it back in data->pwd
		pwd = data->pwd;
		data->pwd = ft_strjoin(pwd, "/.");
		free(pwd);
	}

	// If 'cwd' is not NULL, call the 'change_env_oldpwd' and 'change_env_pwd' functions
	if (cwd)
	{
		change_env_oldpwd(data);
		change_env_pwd(data);
	}

	// Free the memory occupied by 'cwd'
	free(cwd);

	// Return 1 to indicate success
	return (1);
}
