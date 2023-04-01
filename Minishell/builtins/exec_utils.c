
#include "../minishell.h"

/* This function generates all possible file paths based on the input and PATH environment variable */
char **gen_paths(int index, t_data *data, char *input)
{
	/* str stores the value of PATH */
	char *str;

	/* paths will store all the possible file paths */
	char **paths;

	/* temp is used for temporary storage during string manipulation */
	char *temp;

	/* i is a loop index */
	int i;

	i = 0;

	/* str is assigned the value of PATH environment variable */
	str = ft_strdup(&data->env[index][5]);

	/* paths is an array of strings containing all the directories in PATH */
	paths = ft_split(str, ':');

	/* freeing the memory allocated to str */
	free(str);

	/* constructing the file paths using the input and directories in PATH */
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(temp);
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], input);
		free(temp);
		i++;
	}

	/* returning the array of possible file paths */
	return (paths);
}

/* This function checks if the input is an executable in the PATH */
int check_exec_path(char **inputs, t_data *data)
{
	/* i is a loop index */
	int i;

	/* index stores the index of PATH in the environment variable */
	int index;

	/* paths stores all the possible file paths */
	char **paths;

	/* statounet is used to store information about the file */
	struct stat statounet;

	/* Initializing statounet */
	statounet.st_mode = 0;
	i = 0;

	/* Checking if PATH is present in the environment variable */
	index = var_index("PATH=", data);
	if (var_index("PATH=", data) == -1)
		return (0);

	/* Getting the index of PATH in the environment variable */
	index = var_index("PATH=", data);

	/* Getting all the possible file paths */
	paths = gen_paths(index, data, inputs[0]);

	/* Checking if the input is present in any of the directories in PATH */
	while (paths[i])
	{
		stat(paths[i], &statounet);
		if ((statounet.st_mode & S_IXUSR) && !(statounet.st_mode & __S_IFDIR))
		{
			/* freeing the memory allocated to paths */
			free_env(paths);

			/* Returning 1 if the input is present in PATH */
			return (1);
		}
		i++;
	}

	/* freeing the memory allocated to paths */
	free_env(paths);

	/* Returning 0 if the input is not present in PATH */
	return (0);
}


int		check_exec(char **inputs, t_data *data)
{
	int			i; 				// variable to keep track of iterations
	int			ret;			// variable to store return value
	struct stat	statounet;		// variable to store information about a file

	i = 0;
	statounet.st_mode = 0;
	ret = 0;

	// Get information about the file path given in inputs[0]
	stat(inputs[0], &statounet);

	// Check if the given file path contains '/' and is executable by the user and not a directory
	if (ft_strchr(inputs[0], '/') && (statounet.st_mode & S_IXUSR) &&
	!(statounet.st_mode & __S_IFDIR))
	{
		ret = 1; 	// set ret to 1 if the above condition is true
	}
	else
	{
		// If the above condition is false, check for the file in the directories specified in the PATH environment variable
		ret = check_exec_path(inputs, data);
	}
	return (ret);
}
