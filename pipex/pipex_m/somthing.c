/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/05 19:44:32 by jghribi          ###   ########.fr       */
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
	return (0
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
