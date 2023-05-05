/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:57 by jghribi           #+#    #+#             */
/*   Updated: 2023/04/24 14:10:18 by jghribi          ###   ########.fr       */
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
	pid_t	pid;
	int		inf;
	int		outf;
	char	*path_b;
	char	**path_tab_b;
	int		num_arg;
	int		pip_num;
	int		index;
	char	**cmd_tab;
	int		here_doc;
	char	*h_d;
	int		*pip;
	int		arg_c;
	int		*pipe;
}			t_bonus;

void	close_pip(t_bonus *data);
void	ft_dup2(int one, int two);
void	error_b(t_bonus *data, int key);	
void	error_cmd(t_bonus *data, char *cmd);
void	ft_free_b(char **tab);
void	the_end(t_bonus *data);
int		get_files(t_bonus *data, char *in, char *out);
void	ft_path_b(t_bonus *data, char **envp);
int		find_doc(char **argv);
void	here_doc(char *argv, t_bonus *data);
char	*check_cmd_b(char *cmd, t_bonus *data);
void	pipex_b(t_bonus *data, char **argv, int argc, char **envp);
void	child_b(t_bonus *data, char **argv, char **envp);
int		check(char *cmd);
void	check_ls(t_bonus *data, int argc, char **argv, char **envp);
void	check_all_cmd(char **argv, int argc, t_bonus *data);
void	error_cmd2(t_bonus *data, char *cmd);
void	error_death(t_bonus *data);
#endif
