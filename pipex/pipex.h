#ifndef P_I_P_E_X_H
#define P_I_P_E_X_H


#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include <stdio.h>

typedef struct s_bonus
{
	pid_t pid;
	int inf;
	int outf;
	char *path_b;
	char **path_tab_b;
	int num_arg;
	int num_pip;
	int index;
	char **cmd_tab;
	int here_doc;
	int *pipe;
}		t_bonus;	

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

void error_b(t_bonus *data, int key);
void error_cmd(t_bonus *data, char *cmd);
void ft_free_b(char **tab);
void the_end(t_bonus *data);
void pip_close(t_bonus *data);
int get_files(t_bonus *data, char *in, char *out);
void ft_path_b(t_bonus *data, char **envp);
int here_doc(t_bonus *data, char **argv);
void ft_dup2(int one, int two);
char *check_cmd_b(char *cmd, t_bonus *data);
void creat_pipes(t_bonus *data);
void pipex_b(t_bonus *data, char **argv, char **envp);
void child_b(t_bonus *data, char **argv, char **envp);
#endif
