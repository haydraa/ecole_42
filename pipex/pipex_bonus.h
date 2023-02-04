#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"

typedef struct s_bonus
{
	pid_t	pid;
	int		inf;
	int		outf;
	char	*path_b;
	char	**path_tab_b;
	int		num_arg;
	int		num_pip;
	int		index;
	char	**cmd_tab;
	int		here_doc;
	char	*h_d;
	int		pip[2];
	int		pip2[2];
	int		*pipe;
}			t_bonus;

void	error_b(t_bonus *data, int key);	
void	error_cmd(t_bonus *data, char *cmd);
void	ft_free_b(char **tab);
void	the_end(t_bonus *data);
void	pip_close(t_bonus *data);
int		get_files(t_bonus *data, char *in, char *out);
void	ft_path_b(t_bonus *data, char **envp);
int		find_doc(t_bonus *data, char **argv);
void	here_doc(char *argv, t_bonus *data);
char	*check_cmd_b(char *cmd, t_bonus *data);
void	pipex_b(t_bonus *data, char **argv, char **envp);
void	child_b(t_bonus *data, char **argv, char **envp);
int		check(char *cmd);

#endif
