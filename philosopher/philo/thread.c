#include "philo.h"

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(data->necrosyne, NULL) != 0)
		return (1);
	return (0);
}

int	ft_continue(t_data *data)
{
	if (pthread_create(&data->necrosyne, NULL, &checker, (void *)data) != 0)
		clear_error(data);
	usleep(1000);
	if (join_threads(data) == 1)
		return (1);
	return (0);
}

int	creat_threads(t_data *data)
{
	int	i;

	i = 0;
	data->dead = 0;
	data->t0 = get_time();
	if (pthread_mutex_init(&data->protect, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (1);
	while (i < data->nop)
	{
		pthread_mutex_lock(&data->protect);
		data->n_thread = i;
		pthread_mutex_unlock(&data->protect);
		if (pthread_create(&data->philo[i].thread,
				NULL, &routine, (void *)data) != 0)
			return (1);
		i++;
		usleep(1000);
	}
	return (ft_continue(data));
}

int	destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->protect);
	return (0);
}
