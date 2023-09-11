/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:48:57 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/11 17:56:55 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->protect);
	i = data->n_thread;
	pthread_mutex_unlock(&data->protect);
	if (data->notepme > 0)
	{	
		while ((data->notepme > data->philo[i].nota))
			if (routine_execute(data, i) == 1)
				break ;
	}
	else
		while (1)
			if (routine_execute(data, i) == 1)
				break ;
	return (NULL);
}

int	routine_execute(t_data *data, int i)
{
	if (philo_eat(data, i) == 1)
		return (1);
	if (data->notepme != data->philo[i].nota)
	{
		if (philo_think(data, i) == 1)
			return (1);
		if (philo_sleep(data, i) == 1)
			return (1);
	}
	return (0);
}

void	else_funct2(t_data *data, int i)
{
	while (data->dead == 0)
	{
		if (philo_is_dead(data, &i) == 1)
			break ;
	}
}

int	routine_checker(t_data *data, int i)
{
	pthread_mutex_lock(&data->protect2);
	if (i < data->nop && (data->notepme <= data->philo[i].nota))
	{
		pthread_mutex_unlock(&data->protect2);
		return (1);
	}
	if (philo_is_dead(data, &i) == 1)
	{
		pthread_mutex_unlock(&data->protect2);
		return (1);
	}
	else
		pthread_mutex_unlock(&data->protect2);
	return (0);
}

void	*checker(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = 0;
	if (data->notepme > 0)
	{
		while (1)
		{
			if (routine_checker(data, i) == 1)
				break ;
		}
	}
	else
		else_funct2(data, i);
	return (NULL);
}
