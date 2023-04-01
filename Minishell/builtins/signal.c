
#include "../minishell.h"

/* handle_sig function is called when a signal is received by the program.
   If the signal is SIGINT (Ctrl + C), it sets g_status to 130 and prints "minishell>" prompt if possible.
   If the signal is SIGQUIT (Ctrl + \), it performs backspace operation. */
void	handle_sig(int sig)
{
	//int		g_status;
	//char	*g_user_input = 1;

	if (sig == SIGINT)
	{
		/*g_status = 130;
		if (g_user_input)
			ft_putstr_fd("\nminishell> ", 2);
		if (g_user_input)
			free(g_user_input);
		g_user_input = ft_strdup("\0");*/
		ft_putstr_fd("\nminishell> ", 2);
	}
	else if (sig == SIGQUIT)
		write(2, "\b\b  \b\b", 6);
}

/* sig_init function initializes signal handling by calling signal function with SIGINT and SIGQUIT signals.
   If signal function returns SIG_ERR, the program exits with EXIT_FAILURE. */
void	sig_init(void)
{
	if (signal(SIGINT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}

/* handle_exec_sig function is called when a signal is received by the program during execution of commands.
   If the signal is SIGINT (Ctrl + C), it sets g_status to 130 and frees g_user_input.
   If the signal is SIGQUIT (Ctrl + \), it sets g_status to 131 and prints "Exit (core dumped)\n". */
void	handle_exec_sig(int sig)
{
	//int g_status;
	
	if (sig == SIGINT)
	{
		//if (g_user_input)
		//	free(g_user_input);
		//g_status = 130;
		//g_quit = 1;
		write(2, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		//g_status = 131;
		ft_putstr_fd("Exit (core dumped)\n", 2);
	}
}

/* sig_exec_init function initializes signal handling during execution of commands by calling signal function with SIGINT and SIGQUIT signals.
   If signal function returns SIG_ERR, the program exits with EXIT_FAILURE. */
void	sig_exec_init(void)
{
	if (signal(SIGINT, handle_exec_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_exec_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}
