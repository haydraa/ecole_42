/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:48:11 by jghribi           #+#    #+#             */
/*   Updated: 2023/08/15 11:48:12 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nop + 1);
	if (data->forks == NULL)
		return (1);
	while (i < data->nop)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	unlock_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		pthread_mutex_unlock(&data->forks[i]);
		i++;
	}
}

void	fill_struct(t_data *data, int i, int j)
{
	data->philo[i].id = i + 1;
	data->philo[i].nota = 0;
	data->philo[i].time_to_die = 0;
	if (i < j)
	{
		data->philo[i].fork.left = i;
		data->philo[i].fork.right = j ;
	}
	else
	{
		data->philo[i].fork.left = j;
		data->philo[i].fork.right = i ;
	}
	if (pthread_mutex_init(&data->philo[i].mutex, NULL) != 0)
		exit(0);
}

int	creat_philos(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->protect, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		return (1);
	data->philo = malloc(sizeof(t_philo) * (data->nop) + 1);
	if (data->philo == NULL)
		return (1);
	i = 0;
	while (i < data->nop)
	{
		fill_struct(data, i, (i + 1) % data->nop);
		i++;
	}
	return (0);
}
