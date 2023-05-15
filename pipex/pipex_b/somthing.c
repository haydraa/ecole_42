/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:03 by jghribi           #+#    #+#             */
/*   Updated: 2023/05/15 19:31:09 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int one, int two)
{
	dup2(one, 0);
	dup2(two, 1);
}

void	function_of_death(t_bonus *data)
{	
	close_pip(data);
	if (data->outf > 0)
		close(data->outf);
//	ft_close_std();
//	free(data->pip);
	//ft_free_b(data->path_tab_b);
	if (data->inf > 0)
		close(data->inf);
}

int	check(char *cmd)
{
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (!(access(cmd, F_OK)))
			return (1);
	}
	return (0);
}

void	ft_close_std(void)
{
	close(0);
	close(1);
	close(2);
}
