/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:57 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 15:17:23 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"

typedef struct s_bonus
{
	pid_t	*pid;
	int		inf;
	int		outf;
	char	*path_b;
	char	**path_tab_b;
	int		num_arg;
	int		pip_num;
	int		index;
	char	**cmd_tab;
	char	**cmd_args;
	char	*cmd;
	int		here_doc;
	char	*line;
	int		*pip;
	int		pid_index;
}			t_bonus;

void	check_file(t_bonus *data);
void	malloc_pip_pid(t_bonus *data);
void	function_of_death(t_bonus *data);
void	ft_close_std(void);
void	close_pip(t_bonus *data);
void	creat_pip(t_bonus *data);
void	free_child(t_bonus *data, char **cmd_args, char *cmd);
void	ft_dup2(int one, int two);
void	error_b(t_bonus *data, int key);	
void	error_cmd(char *cmd);
void	ft_free_b(char **tab);
void	the_end(t_bonus *data);
int		get_files(t_bonus *data, char *in, char *out);
void	ft_path_b(t_bonus *data, char **envp);
void	here_doc(char *argv, t_bonus *data);
char	*check_cmd_b(char *cmd, t_bonus *data);
void	pipex_b(t_bonus *data, char **argv, int argc, char **envp);
void	child_b(t_bonus *data, char **argv, char **envp);
int		check(char *cmd);
void	check_all_cmd(char **argv, int argc, t_bonus *data);
void	error_cmd2(char *cmd);
void	error_death(t_bonus *data);
#endif
