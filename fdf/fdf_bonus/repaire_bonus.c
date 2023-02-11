/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:36 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/06 15:54:54 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	the_free(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->core_y)
	{
		free(data->tab[i]);
		free(data->repair[i]);
		i++;
	}
	free(data->repair);
	free(data->tab);
}

void	change_tab_sup(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->core_y)
	{
		j = 0;
		while (j < data->core_x)
		{
			if (data->repair[i][j] != 0)
				data->tab[i][j] -= 1;
			j++;
		}
		i++;
	}
}

void	change_tab(t_fdf *data, int index)
{
	int	i;
	int	j;

	i = 0;
	if (index == 1)
	{
		while (i < data->core_y)
		{
			j = 0;
			while (j < data->core_x)
			{
				if (data->repair[i][j] != 0)
					data->tab[i][j] += 1;
				j++;
			}
			i++;
		}
	}
	else if (index == 0)
		change_tab_sup(data);
}

void	repair(t_fdf *data)
{
	int	i;
	int	j;

	j = 0;
	data->repair = ft_calloc(sizeof(int *), data->core_y);
	while (j < data->core_y)
	{
		data->repair[j] = (int *)ft_calloc(data->core_x, sizeof(int));
		j++;
	}
	i = 0;
	while (i < data->core_y)
	{
		j = 0;
		while (j < data->core_x)
		{
			data->repair[i][j] = data->tab[i][j];
			j++;
		}
		i++;
	}
}
