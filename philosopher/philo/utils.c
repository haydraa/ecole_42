#include "philo.h"

int	ft_printf(t_data *data, int id, char *movment)
{
	long long time;

	time = delta_time(data->t0);
	pthread_mutex_lock(&data->write);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->write);
		return (1);
	}
	else
		printf("%lld %d %s" , time, id , movment);
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

int check_numbers(t_data *data)
{
	if (data->nop == 0)
		return (error());
	if (data->time_to_die == 0)
		return (error());
	if (data->time_to_eat == 0)
		return (error());
	if (data->time_to_sleep == 0)
		return (error());
	return (0);
}	
