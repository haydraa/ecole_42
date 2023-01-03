#ifndef P_I_P_E_X_H
#define P_I_P_E_X_H


#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include <stdio.h>



typedef struct s_data
{
	pid_t  pip1;
	pid_t	pip2;
	int end[2];
	int infile;
	int outfile;
	char **cmd1;
	char *path;
	char **path_tab;
	char **cmd_tab;
} t_data;


void parent_pros(t_data *data, char **argv, char **envp);
void	child_pros(t_data *data,char **argv, char **envp);
void pipex(t_data *data, char **argv, char  **envp);
void ft_path(t_data *data, char **argv, char **envp);
char *check_cmd(char *cmd, t_data *data);
void ft_error(t_data *data,char *cmd);
void ft_free(char **tab);
#endif
