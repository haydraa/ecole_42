/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:49:04 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/11 18:11:28 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handel(t_data *data, int key, int i)
{
	if (key == 1)
	{
		if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.left]))
			clear_error(data);
		return (1);
	}
	else if (key == 2)
	{
		if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.left]))
			clear_error(data);
		if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.right]))
			clear_error(data);
		return (1);
	}
	return (0);
}

int	ft_printf(t_data *data, int id, char *movment)
{
	long long	time;

	time = delta_time(data->t0);
	pthread_mutex_lock(&data->write);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->write);
		return (1);
	}
	else
		printf("%lld %d %s", time, id, movment);
	pthread_mutex_unlock(&data->write);
	return (0);
}

void	clear_error(t_data *data)
{
	free(data->philo);
	free(data->forks);
	exit(1);
}

int	error(void)
{
	write(2, "Error args\n", 11);
	return (1);
}

int	check_numbers(t_data *data)
{
	if (data->nop <= 0)
		return (error());
	if (data->time_to_die <= 0 || data->time_to_die > INT_MAX)
		return (error());
	if (data->time_to_eat <= 0 || data->time_to_eat > INT_MAX)
		return (error());
	if (data->time_to_sleep <= 0 || data->time_to_sleep > INT_MAX)
		return (error());
	if (data->notepme < 0 || data->notepme > INT_MAX)
		return (error());
	return (0);
}	
