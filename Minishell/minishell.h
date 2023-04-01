#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"
//# include "./utils/get_next_line.h"

typedef	struct	s_data
{
	char		**env;
	char		*pwd;
}			t_data;

typedef struct s_command_tablaux
{
	char **cmd_tab;
	char *cmd;
}	t_cmd;
/*int				g_status;
char			*g_user_input;
int				g_quit;*/

int				change_pwd(t_data *data, char *input);
void			handle_echo(char **args);
void			handle_cd(char **args, t_data *data);
void			handle_env(char **env);
int				envlen(char **env);
void			free_env(char **env);
char			**dup_env(char **env);
void			handle_exec(char **args, t_data *data);
int				check_exec(char **inputs, t_data *data);
char			**gen_paths(int index, t_data *data, char *input);
void			error_sentence(char *str, int status);
void			handle_exit(char **inputs, t_data *data);
void			handle_export(char **args, t_data *data);
char			**export_env(char **old_env, char *export);
void			replace_var(char *new_var, t_data *data, int index);
int				var_index(char *name, t_data *data);
int				print_export(char **env);
int				check_export(char *str);
int				handle_pipe(char *input1, char *input2, t_data *data);
void			handle_pwd(t_data *data);
void			sig_exec_init(void);
void			sig_init(void);
void			handle_unset(char **inputs, t_data *data);
int		cd_path(char **args, t_data *data);

#endif
