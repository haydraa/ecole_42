/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:10:13 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 15:20:20 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_cmd2(char *cmd)
{
	write(2, "bash: ", 6);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
}

void	error_death(t_bonus *data)
{
	write(2, "Error_args\n", 11);
	close(data->inf);
	close(data->outf);
	close(0);
	close(1);
	close(2);
	ft_free_b(data->path_tab_b);
	exit(1);
}

void	free_child(t_bonus *data, char **cmd_args, char *cmd)
{
	ft_close_std();
	free(data->pid);
	free(data->pip);
	ft_free_b(data->path_tab_b);
	free(cmd);
	ft_free_b(cmd_args);
}

void	check_all_cmd(char **argv, int argc, t_bonus *data)
{
	int		i;
	char	*path;

	if (data->here_doc == 1)
		i = 4;
	else
		i = 2;
	while (i < argc -1)
	{
		if (ft_strcmp(argv[i], "") == 0)
			error_cmd2(argv[i]);
		else
		{
			path = check_cmd_b(argv[i], data);
			if (path == NULL)
				error_cmd2(argv[i]);
			free(path);
		}
		i++;
	}
}

void	creat_pip(t_bonus *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg - 1)
	{
		pipe(data->pip + 2 * i);
		i++;
	}
}
