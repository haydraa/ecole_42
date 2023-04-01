
#include "../minishell.h"

/* check_export function takes a string as an argument and returns 1 if the string is a valid exportable environment variable, 0 otherwise.
A valid exportable environment variable must not start with a digit and only contain alphanumeric characters and "_" symbol.
*/
int		check_export(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))  // check if first character is digit
		return (0);
	while (str[i] && str[i] != '=')  // loop until end of string or '=' symbol
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')  // check if character is alphanumeric or '_' symbol
			return (0);
		i++;
	}
	return (1);
}

/* print_export function takes a double pointer to an environment array as an argument and prints the environment variables in the format of "declare -x [VARNAME]="[VARVALUE]"".
It returns 1 after printing the environment variables.
*/
int		print_export(char **env)
{
	int	i;
	int j;
	int	equal;

	i = -1;
	while (env[++i])
	{
		equal = 1;
		j = 0;
		ft_putstr("declare -x ");  // print the prefix of the environment variable
		while (env[i][j])
		{
			if (env[i][j] == '\\' || env[i][j] == '$' || env[i][j] == '\"')  // check if the character is a special character that needs to be escaped
				write(1, "\\", 1);  // add escape character
			write(1, &env[i][j], 1);  // print the character
			if (env[i][j] == '=' && equal-- == 1)  // check if it is the first occurrence of '='
				write(1, "\"", 1);  // add double quotes after '=' symbol
			j++;
		}
		if (equal != 1)  // check if the value of the environment variable is not empty
			write(1, "\"", 1);  // add double quotes after value of the environment variable
		write(1, "\n", 1);  // add newline character
	}
	return (1);
}
