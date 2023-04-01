
#include "../minishell.h"

void handle_echo(char **args)
{
	int i; // variable to iterate through the arguments
	int n_flag; // flag to indicate if the -n option was passed

	i = 1; // start at the first argument, ignoring the command name
	n_flag = 0; // initialize n_flag to 0
	//g_status = 0; // global status variable

	// check if the current argument is -n, and if so, set the n_flag
	while (args[i] && !ft_strcmp(args[i], "-n") && i++)
		n_flag = 1;

	// loop through the remaining arguments and print them to standard output
	while (args[i])
	{
		// write the current argument to standard output
		write(1, args[i], ft_strlen(args[i]));

		// if there is a next argument, add a space character
		if (args[i + 1])
			write(1, " ", 1);

		i++; // move on to the next argument
	}

	// if the -n option was not passed, write a newline character
	if (!n_flag)
		write(1, "\n", 1);
}
