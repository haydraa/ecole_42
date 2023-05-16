/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/16 14:06:19 by jghribi          ###   ########.fr       */
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
		write(2, "infile is correpted\n", 20);
	data->outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->outfile < 0)
		write(2, "outfile is correpted\n", 21);
	if (data->outfile < 0 && data->infile < 0)
		return (1);
	return (0);
}

void	ft_close(t_data *data)
{
	close(data->end[0]);
	close(data->end[1]);
}

void	error_final(char *cmd, t_data *data)
{
	ft_error(cmd);
	if (data->infile > 0)
		close(data->infile);
	if (data->outfile > 0)
		close(data->outfile);
	ft_free(data->path_tab);
	ft_close_std();
	exit(1);
}
