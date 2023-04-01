
#include "../minishell.h"

/* This function executes a command that is passed as an argument with its arguments.
   It searches the PATH variable for the location of the executable. */
int		execute_2(char **inputs, t_data *data)
{
	int			i;
	char		**paths;
	int			index;
	struct stat	statounet;

	i = 0;
	/* Initialize statounet.st_mode to 0 */
	statounet.st_mode = 0;
	/* Get the index of the "PATH=" variable */
	index = var_index("PATH=", data);
	/* Generate the possible paths based on the "PATH=" variable */
	paths = gen_paths(index, data, inputs[0]);
	/* Iterate through the paths and execute the first one that has execute permission */
	while (paths[i])
	{
		/* Get information about the file at the current path */
		stat(paths[i], &statounet);
		/* Check if the file has execute permission and can be executed */
		if ((statounet.st_mode & S_IXUSR) &&
		(execve(paths[i], inputs, data->env) != -1))
			return (0);
		i++;
	}
	/* Free the memory occupied by the paths */
	free_env(paths);
	return (1);
}

/* This function executes a command. It first checks if the command is an absolute path or not.
   If it is an absolute path and has execute permission, it is executed.
   Otherwise, it searches the PATH variable for the location of the executable. */
int		execute(char **inputs, t_data *data)
{
	int			index;
	struct stat	statounet;

	/* Initialize statounet.st_mode to 0 */
	statounet.st_mode = 0;
	/* Get the index of the "PATH=" variable */
	index = var_index("PATH=", data);
	/* Get information about the file at the current path */
	stat(inputs[0], &statounet);
	/* Check if the command has a "/" in its name (i.e. an absolute path) and has execute permission */
	if (ft_strchr(inputs[0], '/') && (statounet.st_mode & S_IXUSR) &&
	(execve(inputs[0], &inputs[0], data->env) != -1))
		return (0);
	else if (index >= 0)
	{
		/* If the PATH variable is set, search for the location of the executable */
		if (!execute_2(inputs, data))
			return (0);
	}
	return (1);
}


void handle_exec(char **inputs, t_data *data)
{
	int	g_status;

    pid_t   pid; //pid for forked process
    int     status; //status of the process

    status = 0;
    //Check if the input command is a built-in command or not.
    if (!check_exec(inputs, data))
    {
        //if not, print an error message and return with exit status 127
        return (error_sentence("\t\tminishell: Unknown command\n", 127));
    }
    //create a child process
    pid = fork();
    if (pid == 0) //child process
    {
        //try to execute the command
        if (execute(inputs, data) != 0)
        {
            //if execution failed, exit with error number
            exit(errno);
        }
        //exit child process with success status
        exit(EXIT_SUCCESS);
    }
    else if (pid < 0) //fork failed
    {
        //exit with failure status
        exit(EXIT_FAILURE);
    }
    else //parent process
    {
        //initialize signals for child process execution
        sig_exec_init();
        //wait for child process to complete
        waitpid(pid, &status, 0);
    }
    //update global status with the exit status of the child process
    g_status = WEXITSTATUS(status);
    //if global quit flag is set, update global status with 130
    /*if (g_quit)
    {
        g_status = 130;
    }*/
}
