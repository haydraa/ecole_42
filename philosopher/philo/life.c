#include "philo.h"

int		eat(t_data *data, int i)
{
	if (pthread_mutex_lock(&data->forks[data->philo[i]]))
}
