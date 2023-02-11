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
		else if ((arg[i] < '0' || arg[i] > '9'))
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
			if (ft_doubel(ft_atol(tab[i]),ft_atol(tab[i + j])) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_doubel(int str, int s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == s)
		return 0;
	if (str > 2147483647 || str < -2147483648)
		return 0;
	//if ()
	/*	while (str[i] || s[j])
	{
		if (str[i] != s[j])
			return (1);
		i++;
		j++;
	}*/
	return 1;
}
