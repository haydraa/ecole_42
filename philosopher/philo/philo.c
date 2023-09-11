/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:48:57 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/08 16:03:41 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	else_function(t_data *data, int i)
{
	while (1)
	{
		if (routine_execute(data, i) == 1)
			break ;
	}
}

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
	//	pthread_mutex_lock(&data->write);
		while ((data->notepme > data->philo[i].nota) && data->dead == 0)
		{
	//		pthread_mutex_unlock(&data->write);
			routine_execute(data, i);
		}
	}
	else
		else_function(data, i);
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

void	*checker(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = 0;
	if (data->notepme > 0)
	{
		pthread_mutex_lock(&data->protect2);
		while (data->philo[i].nota && (data->notepme > data->philo[i].nota)
			&& data->dead == 0)
		{
			if (philo_is_dead(data, &i) == 1)
			{
				pthread_mutex_unlock(&data->protect2);
				break ;
			}
		//	else
		//		pthread_mutex_unlock(&data->protect);
		}
	}
	else
		else_funct2(data, i);
	return (NULL);
}
