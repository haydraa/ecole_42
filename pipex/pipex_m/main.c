/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:33:34 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 14:32:44 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!data->path)
	{
		data->path = ft_calloc(1, sizeof(char));
		data->path_tab = ft_split(data->path, ':');
		free(data->path);
	}
	else
		data->path_tab = ft_split(data->path, ':');
}

void	check_m(t_data *data, char **argv)
{
	char	*cmd;
	char	*cmd2;

	cmd = check_cmd(argv[2], data);
	cmd2 = check_cmd(argv[3], data);
	if (cmd == NULL && cmd2 == NULL)
	{
		ft_free(data->path_tab);
		if (data->infile > 0)
			close(data->infile);
		if (data->outfile > 0)
			close(data->outfile);
		free(cmd);
		free(cmd2);
		write(2, "Error_Commands\n", 16);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	else
	{
		free(cmd);
		free(cmd2);
	}
}

char	*find_true(char *cmd)
{
	char	*path_ac;

	path_ac = ft_strdup(cmd);
	if (!(access(path_ac, F_OK)))
		return (path_ac);
	free(path_ac);
	return (NULL);
}

char	*check_cmd(char *cmd, t_data *data)
{
	char	*slash;
	char	*path_ac;
	int		i;

	i = -1;
	if (check(cmd) == 1)
		return (find_true(cmd));
	if (ft_strcmp(cmd, "") == 0)
		return (NULL);
	data->cmd1 = ft_split(cmd, ' ');
	while (data->path_tab[++i])
	{
		slash = ft_strjoin(data->path_tab[i], "/");
		path_ac = ft_strjoin(slash, data->cmd1[0]);
		free(slash);
		if (!(access(path_ac, F_OK)))
		{
			ft_free(data->cmd1);
			return (path_ac);
		}
		free(path_ac);
	}
	ft_free(data->cmd1);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		ft_error_args();
	if (open_fds(argc, argv, &data) == 1)
		return (0);
	ft_path(&data, envp);
	pipex(&data, argv, envp);
	if (data.infile > 0)
		close(data.infile);
	if (data.outfile > 0)
		close(data.outfile);
	ft_close_std();
	ft_free(data.path_tab);
	return (0);
}
