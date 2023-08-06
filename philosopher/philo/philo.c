#include "philo.h"

void	*routine(void *arg)
{
	t_data *data;
	int		i;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->protect);
	i = data->n_thread;
	pthread_mutex_unlock(&data->protect);
	if (data->notepme > 0)
	{	
		pthread_mutex_lock(&data->write);
		while ((data->notepme > data->philo[i].nota) && data->dead == 0)
		{
			pthread_mutex_unlock(&data->write);
			routine_execute(data, i);
		}
	}
	else
	{
		pthread_mutex_lock(&data->write);
		while (data->dead == 0)
		{
			pthread_mutex_unlock(&data->write);
			if (routine_execute(data, i) == 1)
					break ;
		}
		//pthread_mutex_unlock(&data->dead_mutex);
	}
	return (NULL);
}

int		routine_execute(t_data *data, int i)
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

void	*checker(void *args)
{
	t_data *data;
	int	i;

	data = (t_data *)args;
	i = 0;
	if (data->notepme > 0)
	{
		pthread_mutex_lock(&data->protect);
		while ((data->notepme > data->philo[i].nota)
				&& data->dead == 0)
		{
			if (philo_is_dead(data, &i) == 1)
			{
				pthread_mutex_unlock(&data->protect);
				break ;
			}
		}
	}
	else
	{
		while(data->dead == 0)
		{
			if (philo_is_dead(data, &i) == 1)
			{
				break ;
			}
		}
	}
	return (NULL);
}
