#ifndef P_I_P_E_X_H
#define P_I_P_E_X_H


#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
typedef struct s_data
{
	pid_t  pip1;
	pid_t	pip2;
	int file1;
	int file2;
	char *cmd1;
	char *cmd2;
	char *path;
	char **path_tab;
} t_data;


//void parent_pros(t_data *data);
//void	child_pros(t_data *data);
//void pipex(t_data *data);
void display(t_data *data);
void ft_path(t_data *data, char **argv, char **envp);
char *check_cmd(char *cmd, t_data *data);
#endif
