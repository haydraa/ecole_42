/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:55:50 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/04 15:55:51 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

int	ft_continue(t_semiph *semiph, int num, int i)
{
	if (i == 4)
	{
		if (num == 0)
			return (-1);
		semiph->time_to_sleep = num;
	}
	if (i == 5)
	{
		if (num == 0)
			semiph->notepme = -1;
		else
		{
			semiph->notepme = num;
			semiph->current_eat = 0;
			semiph->max_eat = num * semiph->n_philo;
		}
	}
	return (0);
}

int	ft_set_data(t_semiph *semiph, int num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (-1);
		semiph->n_philo = num;
	}
	else if (i == 2)
	{
		if (num == 0)
			return (-1);
		semiph->time_to_die = num;
	}
	else if (i == 3)
	{
		if (num == 0)
			return (-1);
		semiph->time_to_eat = num;
	}
	else
		if (ft_continue(semiph, num, i) == -1)
			return (-1);
	return (0);
}

int	check_number(char *nmb)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (nmb[i])
	{
		if (nmb[i] >= '0' && nmb[i] <= '9')
			num = num * 10 + (nmb[i] - '0');
		else
			return (-1);
		i++;
	}
	return (num);
}

int	ft_check(char **argv, t_semiph *semiph)
{
	int	num;
	int	i;

	i = 1;
	while (argv[i])
	{
		num = check_number(argv[i]);
		if (num == -1)
			return (-1);
		if (ft_set_data(semiph, num, i))
			return (-1);
		i++;
	}
	if (i == 5)
	{
		semiph->notepme = -1;
		semiph->current_eat = -1;
		semiph->max_eat = -1;
	}
	return (0);
}
