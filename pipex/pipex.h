/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:15 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/18 16:46:43 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	pid_t	pip1;
	pid_t	pip2;
	int		end[2];
	int		infile;
	int		outfile;
	char	**cmd1;
	int		error;
	char	*path;
	char	**path_tab;
	char	**cmd_tab;
}			t_data;

void	ft_error_args(void);
void	child2_pros(t_data *data, char **argv, char **envp);
void	child1_pros(t_data *data, char **argv, char **envp);
void	pipex(t_data *data, char **argv, char **envp);
void	ft_path(t_data *data, char **argv, char **envp);
void	ft_close(t_data *data);
char	*check_cmd(char *cmd, t_data *data);
void	ft_error(t_data *data, char *cmd);
void	ft_free(char **tab);
int		check(char *cmd);
void	ultimate_close(t_data *data);
void	ft_close_std(void);

#endif
