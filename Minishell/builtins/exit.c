
#include "../minishell.h"

/*
** error_sentence: outputs the given error string `str` to the standard error
** and sets the global variable `g_status` to `status`.
*/
void error_sentence(char *str, int status)
{
	int g_status = 0;

    g_status = status;
    ft_putstr_fd(str, 2);
}

/*
** is_number: returns 1 if `str` is a string representation of a number, 0 otherwise.
*/
int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

/*
** handle_exit: frees all the memory used by the program and exits with the exit
** status `g_status`. If an argument is passed, the exit status is set to the
** integer representation of the argument. If multiple arguments are passed,
** outputs an error message.
*/
void handle_exit(char **inputs, t_data *data)
{
	int	g_status;
	
    g_status = 0;
    if (inputs[1])
    {
        if (is_number(inputs[1]))
        {
            if (inputs[2])
                return (error_sentence("\tminishell: too many argument\n", 2));
            g_status = ft_atoi(inputs[1]);
            if (g_status > 255)
                g_status = 255;
            else if (g_status < 0)
                g_status = 255;
        }
        else
            error_sentence("\t\tminishell: numeric argument is required\n", 2);
    }
    free_env(inputs);
    free(data->pwd);
    free_env(data->env);
    exit(g_status);
}
