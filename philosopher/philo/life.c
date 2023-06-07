#include "philo.h"

int drop_function(t_data *data, int i)
{
	if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.left]))
		clear_error(data);
	if (pthread_mutex_unlock(&data->forks[data->philo[i].fork.right]))
		clear_error(data);
	pthread_mutex_lock(&data->protect);
	data->philo[i].nota++;
	pthread_mutex_unlock(&data->protect);
	return (0);

}

int		philo_eat(t_data *data, int i)
{
	if (pthread_mutex_lock(&data->forks[data->philo[i].fork.left]) != 0)
		return (1);
	if (ft_printf(data, data->philo[i].id, "has taken a fork\n") == 1)
		return (1);
	if (pthread_mutex_lock(&data->forks[data->philo[i].fork.right]) != 0)
		return (1);
	if (ft_printf(data, data->philo[i].id, "has taken a fork\n" ) == 1)
		return (1);
	if (ft_printf(data, data->philo[i].id, "is eating\n" ) == 1)
		return (1);
	pthread_mutex_lock(&data->dead_mutex);
	data->philo[i].time_to_die = get_time();
	pthread_mutex_unlock(&data->dead_mutex);
	exec_action(data->time_to_eat);
	drop_function(data, i);
	return (0);
}

int	philo_sleep(t_data *data, int i)
{
	if (ft_printf(data, data->philo[i].id, "is sleeping\n")== 1)
			return (1);
	exec_action(data->time_to_sleep);
	return (0);
}

int	philo_think(t_data *data, int i)
{
	if (ft_printf(data, data->philo[i].id, "is thinking\n")== 1)
		return (1);
	return (0);
}

int philo_is_dead(t_data *data, int *i)
{
	int	time;

	if (*i == data->nop)
		 *i = 0;
	pthread_mutex_lock(&data->dead_mutex);
	time = delta_time(data->philo[*i].time_to_die);
	pthread_mutex_unlock(&data->dead_mutex);
	if (time > data->time_to_die)
	{
		pthread_mutex_lock(&data->protect);
		ft_printf(data, data->philo[*i].id, "is dead\n");
		pthread_mutex_lock(&data->dead_mutex);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		pthread_mutex_unlock(&data->protect);
		return (1);
	}
	(*i)++;
	return (0);
}
