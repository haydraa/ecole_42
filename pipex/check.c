#include "pipex.h"



int check_command(char *cmd1, char *cmd2)
{

		ft_printf("here");
		if (ft_strnstr(cmd1, "/" ,ft_strlen(cmd1)))
				ft_printf("here\n");
		if (ft_strnstr(cmd2, "/" ,ft_strlen(cmd2)))
						ft_printf("here\n");

		return 0;
}	

