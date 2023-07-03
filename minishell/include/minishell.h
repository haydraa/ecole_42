/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 16:05:05 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

typedef struct s_cmd_list
{
	char				*cmd;
	int					*redir_type;
	char				**redir_file;
	struct s_cmd_list	*next;
}	t_cmd_list;

typedef struct s_env_list
{
	char				*name;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_data1
{
	int			squote;
	int			dquote;
	int			r_tabl;
	char		**paths;
	char		**arg_tabl;
	int			path_nbr;
	int			here_doc_nbr;
	int			here;
}	t_data1;

typedef struct s_data2
{
	int			lst_nbr;
	int			nbr;
	char		*full_path;
	int			i;
	char		*result;
	int			pid;
	int			exit_s;
	int			close_l;
	int			li;
	int			ly;
	int			j;
	int			rdj;
	int			x;
}	t_data2;

typedef struct s_data3
{
	int			exec_i;
	int			lexer_error;
	int			redir_error;
	int			lexer_start;
	int			houna;
	int			export_num;
	int			path;
	int			error_getcmd;
	int			main_error;
	int			fd;
	char		*file;
	int			**fds;
	int			pid;
	int			rdi;
	int			pskip;
	char		*pcommand;
}	t_data3;

typedef struct s_data4
{
	int			*redir_type;
	char		**redir_file;
	int			tabl_s;
	char		*value;
	char		*name;
	int			parser_error;
	int			rd_error;
	int			is_built_in;
	int			bin_nbr;
	int			nbr_save;
	int			fds_malloced;
	int			free_i;
	int			sit;
	int			unset;
	int			e;
	int			set;
	int			f;
}	t_data4;

typedef struct s_data5
{
	char		*str_f;
	int			ppi;
	int			echo_i;
	int			echo_j;
	char		*str;
	char		**tabl;
	int			i;
	int			file_error;
	int			finale;
	int			echo_n;
	int			is_pipe;
	int			lol;
	int			stdin_save;
	int			stdout_save;
	int			last_error;
}	t_data5;

typedef struct s_var
{
	int		i;
	int		j;
	int		k;
	char	*result;
	int		newlen;
}		t_var;

typedef struct s_data
{
	char		*main_str;
	int			bsn;
	int			sigint;
	int			close_need;
	int			hell;
	int			str_exit;
	int			i;
	t_cmd_list	*cmd_table;
	t_cmd_list	*cmd_table_temp;
	t_env_list	*env_table;
	t_env_list	*env_table_sorted;
	t_data1		data1;
	t_data2		data2;
	t_data3		data3;
	t_data4		data4;
	t_data5		data5;
}				t_data;

extern t_data	*g_data;
/* -------------------------------------------------------------------------- */
/*                                   parsing                                  */
/* -------------------------------------------------------------------------- */

void		find_dollar(t_data *data);
int			ft_lexer(char *str, t_data *data);
int			ft_parser(char *str, t_data *data, int end);
void		ft_addpipe(t_data *data);
void		here(t_data *data);
void		quotes_switch(t_data *data, char *str, int i);
int			redir_parsing(char *str, t_data *data);
void		free_child(t_data *data);
int			count_redir(char *str, t_data *data);
int			str_is_empty(char *str);
int			here_doc_fct(t_data *data, char *str);
int			ft_lexer2(t_data *data, char *str);
int			ft_parser2(t_data *data, char *str);
char		*create_here_doc_file(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                     env                                    */
/* -------------------------------------------------------------------------- */

int			ft_env_var(t_data *data);
int			ft_put_env_in_lst(t_data *data, char **env);
void		ft_sort_list(t_data *data);
t_env_list	*ft_dup_list(t_env_list *list);
void		ft_insertion_sort(t_data *data);
int			ft_search_and_replace_env_var(t_data *data);
void		ft_replace_var_env(t_cmd_list *cmd_list, int pos, t_data *data);
char		*ft_is_var_env(t_data *data, char *cmd, int pos, int len);
char		*ft_search_and_change_env_var(t_data *data, char *str);
char		*ft_change_var_env(char *str, int pos, t_data *data);
t_env_list	*ft_env_lstnew(char *name, char *value);
void		ft_env_lstadd_front(t_env_list **alst, t_env_list *new);
int			ft_env_lstsize(t_env_list *lst);
t_env_list	*ft_env_lstlast(t_env_list *lst);
void		ft_env_lstadd_back(t_env_list **lst, t_env_list *new);
void		ft_env_lstclear(t_env_list **lst);

/* -------------------------------------------------------------------------- */
/*                                    exec                                    */
/* -------------------------------------------------------------------------- */

int			ft_execution(t_data *data, char **env);
char		**recup_path(t_data *data);
void		ultimate_free(t_data *data, int key);
int			continue_1(t_data *data);
char		*recupathline(char **env);
int			exec_one_cmd(t_data *data, char **env);
char		**get_cmd(t_data *data);
char		**put_cmd_in_arg(int i, t_data *data, char *str, char **tabl);
int			get_argnbr(char *str, t_data *data);
int			put_path(t_data *data);
int			cmd_redir(t_data *data, char **env, int nbr);
int			exec_cmds(t_data *data, char **env);
void		while_1(t_data *data);
void		wait_loop(t_data *data);
void		free_if_cmd_fail(t_data *data);
char		**rm_quote(char **tabl, t_data *data);
char		*rm_quote2(t_data *data, char **tabl, char *str);
int			forward_redir(t_data *data, int i);
int			backward_redir(t_data *data, int i, int nbr);
int			getcmd_and_pipe(t_data *data, char **env);
int			getcmd_and_pipe_two(t_data *data);
int			exec_cmds_second(t_data *data, char **env);
void		exec_cmds_two(t_data *data);
void		getcmd_and_pipe_three(t_data *data);
char		**allocate_tabl(t_data **data);
char		**fill_tabl(t_data **data, char *str, char **tabl);
void		continue_3(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                  builtins                                  */
/* -------------------------------------------------------------------------- */
void		handler(int sigtype);
void		exekerror3(t_data *data);
void		handle_directory_error(t_data *data);
void		exekerror2(t_data *data);
int			count_tabel(char **tab);
void		handler2(int sigtype);
int			built_in(t_data *data, char **env, int nbr);
int			ft_is_builtin(t_data *data, const char *s1);
void		bin_env(t_data *data);
void		error_handel_tow(t_data *data);
int			bin_pwd(t_data *data);
void		bin_cd(t_data *data);
void		co_8(char *name, char *value, char **arg, t_data *data);
void		export_msg(char *str, t_data *data);
int			first_enter(char **arg, t_data *data);
void		co_7(t_env_list *p_env_name, char *name, t_data *data, char *value);
int			continue_6(char **arg, t_data *data, int key);
void		export_msg(char *str, t_data *data);
char		*ft_chr_var_env(t_data *data, char *str);
void		ft_update_var_env(t_data *data, char *name, char *value);
void		bin_export(char **arg, t_data *data);
void		ft_display_env(t_env_list *list);
t_env_list	*ft_search_env(t_data *data, char *name);
int			ft_correct_env_name(char **arg, t_data *data);
void		ft_wrong_env_name(char **arg, t_data *data);
void		free_continue_9(t_data *data);
void		bin_unset(char **arg, t_data *data);
t_env_list	*ft_search_preenv(t_data *data, char *name);
void		ft_remove_env_var(char **arg, t_data *data);
void		ft_name_error(char **arg, t_data *data);
void		ft_clear_first_elmt(t_data *data);
void		ft_clear_elmt(t_data *data, char *name);
int			bin_echo(t_data *data);
void		bin_exit(t_data *data, int pipe);
void		error_handel(t_data *data);
int			parserror(int nbr, t_data *data);
void		free_printf(t_data *data);
void		exekerror(int nbr, t_data *data);
int			str_is_empty(char *str);
void		setup_term(int save);
void		ft_free_all(t_data *data);
void		main_fonction_two(t_data *data);
int			is_number(char *str);
void		ft_continue_exit(t_data *data);
void		free_redir_fail_next(t_data *data);
void		free_exit_pipe_next(t_data *data);
int			check_for_exit(t_data *data);
void		free_for_exit(t_data *data);
void		execkerror_utils(t_data *data);
void		free_start(t_data *data);
int			ft_isdigit(int c);
void		bin_exit_next(t_data *data, int flag);
void		free_for_redir_fail(t_data *data);
void		free_exit_pipe(t_data *data);
int			parserror2(int nbr, t_data *data);
void		exekerror_utils(t_data *data);
void		print_command_not_found(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    utils                                   */
/* -------------------------------------------------------------------------- */
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_continue3(t_data *data);
void		ft_continue2(t_data *data, char *str);
void		close_hell(t_data *data);
char		*ft_strmjoin(char *s1, char c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalnum(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_replace_word(char *str, int start, int len, char *word);
int			ft_strncmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_1ststrjoin(char *s1, char *s2);
int			main_utils_2(t_data *data, int i);
char		*ft_strjoin_c(char *s1, char c);
int			str_diff(char *str1, char *str2);
char		*ft_malloc_str(char *s1);
void		ft_putendl(char *s);
void		init_main(t_data *data);
char		*ft_found_path(t_data *data, char *str);
int			ft_intlen(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
t_cmd_list	*ft_lstnew(char *cmd, int *redir_type, char **redir_file);
void		ft_lstadd_front(t_cmd_list **alst, t_cmd_list *new);
int			ft_lstsize(t_cmd_list *lst);
t_cmd_list	*ft_lstlast(t_cmd_list *lst);
void		ft_lstadd_back(t_cmd_list **alst, t_cmd_list *new);
void		ft_lstclear(t_data *data, t_cmd_list **lst);
int			ft_is_chr(char c, t_data *data);
int			check_rl(void);
int			stupid_problem(t_data *data, char *str);
void		free_fds_error(t_data *data);
int			stupid_problem(t_data *data, char *str);
int			finish_stupid(t_data *data, char *str, int x, int j);
int			check_stupid_quotes(char *str);
void		free_if_execv_fail(t_data *data);
int			main_utils(t_data *data);
void		ft_close_for_fun(void);
int			ft_isdigit(int c);
int			continue_func(t_data *data);
int			while_redir(t_data *data, int i, int nbr);
void		execkerror_utils(t_data *data);
char		**ft_split(char const *s, char c);

#endif
