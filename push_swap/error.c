/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:20:30 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/11 19:29:43 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (arg[i + 1] == '-' || arg[i + 1] == '+' || arg[i + 1] == ' ')
				return (0);
		}
		else if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}	
	return (1);
}

int	void_arg(int argc, char **argv)
{
	int	i;
	int	len;
	int	x;

	i = 1;
	while (i < argc)
	{
		if (argv[i][x] >= '0' && argv[i][x] <= '9')
			if (argv[i][x + 1] >= 33 && argv[i][x + 1] <= 47)
				return (0);
		len = 0;
		x = 0;
		if (ft_strlen(argv[i]) == 0)
			return (0);
		else if (ft_strlen(argv[i]) == 1)
			if (argv[i][x] < '0' || argv[i][x] > '9')
				return (0);
		len = ft_strlen(argv[i]);
		while (argv[i][x] == ' ')
			x++;
		if (len == x)
			return (0);
		i++;
	}
	return (1);
}

int	to_dob(char **tab)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 1;
	while (tab[x])
			x++;
	while (i < x)
	{
		j = 1;
		while (i + j < x)
		{
			if (ft_doubel(ft_atol(tab[i]), ft_atol(tab[i + j])) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_doubel(long str, long s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == s)
		return (0);
	if (s > 2147483647 || s < -2147483648)
		return (0);
	if (str > 2147483647 || str < -2147483648)
		return (0);
	return (1);
}
