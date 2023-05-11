/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:38 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/09 18:33:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_files(t_bonus *data, char *in, char *out)
{
	data->inf = open(in, O_RDONLY);
	if (data->inf < 0)
		return (1);
	data->outf = open(out, O_RDWR | O_TRUNC | O_CREAT, 0000644);
	if (data->outf < 0)
	{	
		if (data->here_doc != 1)
			close(data->inf);
		return (1);
	}
	return (0);
}

void	ft_path_b(t_bonus *data, char **envp)
{
	int	i;

	i = 0;
	data->path_b = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path_b = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!data->path_b)
	{
		data->path_b = ft_calloc(1, sizeof(char));
		data->path_tab_b = ft_split(data->path_b, ':');
		free(data->path_b);
	}
	else
		data->path_tab_b = ft_split(data->path_b, ':');
}

int	find_doc(t_bonus *pi, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		if (argc < 6)
			error_b(pi, 0);
		here_doc(argv[2], pi);
		pi->outf = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0000644);
		if (pi->outf < 0)
		{
			close(pi->inf);
			return (0);
		}
		return (1);
	}
	return (0);
}

char	*check_cmd_b(char *cmd, t_bonus *data)
{
	char	*slash;
	char	*path_ac;
	int		i;

	i = -1;
	if (ft_strlen(cmd) == 0)
		error_b(data, 4);
	if (check(cmd) == 1)
		return (cmd);
	data->cmd_tab = ft_split(cmd, ' ');
	while (data->path_tab_b[++i])
	{
		slash = ft_strjoin(data->path_tab_b[i], "/");
		path_ac = ft_strjoin(slash, data->cmd_tab[0]);
		free(slash);
		if (!(access(path_ac, F_OK)))
		{
			ft_free_b(data->cmd_tab);
			return (path_ac);
		}
		free(path_ac);
	}
	ft_free_b(data->cmd_tab);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_bonus	pi;

	pi.index = 2;
	if (argc < 5)
		error_b(&pi, 0);
	pi.here_doc = find_doc(&pi, argc, argv);
	if (pi.here_doc == 0)
		if (get_files(&pi, argv[1], argv[argc - 1]) == 1)
			error_b(&pi, 1);
	pi.num_arg = argc - 3 - pi.here_doc;
	pi.pip_num = 2 * (pi.num_arg - 1);
	if (pi.num_arg == 1)
		return (0);
	ft_path_b(&pi, envp);
	pipex_b(&pi, argv, argc, envp);
}
