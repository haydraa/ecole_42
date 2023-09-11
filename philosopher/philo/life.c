/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:48:27 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/08 16:03:21 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drop_function(t_data *data, int i)
{
	if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.left]))
		clear_error(data);
	if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.right]))
		clear_error(data);
	return (0);
}

int	philo_eat(t_data *data, int i)
{
	if (pthread_mutex_lock(&data->forks[data->philo[i].fork.left]) != 0)
		return (1);
	if (ft_printf(data, data->philo[i].id, "has taken a fork\n") == 1)
		return (error_handel(data, 1, i));
	if (pthread_mutex_lock(&data->forks[data->philo[i].fork.right]) != 0)
		return (1);
	if (ft_printf(data, data->philo[i].id, "has taken a fork\n" ) == 1)
		return (error_handel(data, 2, i));
	if (ft_printf(data, data->philo[i].id, "is eating\n" ) == 1)
		return (error_handel(data, 2, i));
	pthread_mutex_lock(&data->dead_mutex);
	data->philo[i].time_to_die = get_time();
	pthread_mutex_unlock(&data->dead_mutex);
	exec_action(data->time_to_eat);
	drop_function(data, i);
	pthread_mutex_lock(&data->protect3);
	data->philo[i].nota++;
	pthread_mutex_unlock(&data->protect3);
	return (0);
}

int	philo_sleep(t_data *data, int i)
{
	if (ft_printf(data, data->philo[i].id, "is sleeping\n") == 1)
		return (1);
	exec_action(data->time_to_sleep);
	return (0);
}

int	philo_think(t_data *data, int i)
{
	if (ft_printf(data, data->philo[i].id, "is thinking\n") == 1)
		return (1);
	return (0);
}

int	philo_is_dead(t_data *data, int *i)
{
	int	time;

	if (*i == data->nop)
		*i = 0;
	pthread_mutex_lock(&data->dead_mutex);
	time = delta_time(data->philo[*i].time_to_die);
	pthread_mutex_unlock(&data->dead_mutex);
	if (time > data->time_to_die)
	{
		ft_printf(data, data->philo[*i].id, "is dead\n");
		pthread_mutex_lock(&data->write);
		data->dead = 1;
		pthread_mutex_unlock(&data->write);
		return (1);
	}
	(*i)++;
	return (0);
}
