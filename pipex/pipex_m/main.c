/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:33:34 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/09 17:37:10 by jghribi          ###   ########.fr       */
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

void	error_final(char *cmd, t_data *data)
{
	ft_error(cmd);
	close(data->infile);
	close(data->outfile);
	ft_free(data->path_tab);
	ft_close_std();
	exit(1);
}

char	*check_cmd(char *cmd, t_data *data)
{
	char	*slash;
	char	*path_ac;
	int		i;

	i = -1;
	if (ft_strcmp(cmd, "") == 0)
		error_final(cmd, data);
	if (check(cmd) == 1)
	{
		path_ac = ft_strdup(cmd);
		return (path_ac);
	}
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

void	check_m(t_data *data, char **argv)
{
	char	*cmd;
	char	*cmd2;

	cmd = check_cmd(argv[2], data);
	cmd2 = check_cmd(argv[3], data);
	if (cmd == NULL || cmd2 == NULL)
	{
		ft_free(data->path_tab);
		close(data->infile);
		close(data->outfile);
		free(cmd);
		free(cmd2);
		write(2, "Error_args\n", 12);
		ft_close_std();
		exit(EXIT_FAILURE);
	}
	else 
	{
		free(cmd);
		free(cmd2);
	}
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
	close(data.infile);
	close(data.outfile);
	ft_close_std();
	ft_free(data.path_tab);
	return (0);
}
