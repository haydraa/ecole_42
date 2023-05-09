/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/09 17:29:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check(char *cmd)
{
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (!(access(cmd, F_OK)))
			return (1);
	}
	return (0);
}

int	open_fds(int argc, char **argv, t_data *data)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		write(2, "bash: ", 6);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 29);
		ft_close_std();
		return (1);
	}
	data->outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->outfile < 0)
	{
		close(data->infile);
		write(2, "outfile is correpted\n", 21);
		ft_close_std();
		return (1);
	}
	return (0);
}

int	ls_forbiden(char **argv)
{
	if (ft_strcmp(argv[3], "") == 0)
		return (1);
	if (ft_strcmp(argv[2], "") == 0)
		return (1);
	return (0);
}

void	ft_close(t_data *data)
{
	close(data->end[0]);
	close(data->end[1]);
}
