#include "philo.h"

void creat_forks(t_data *data)
{
	int i;
	
	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nop + 1);
	if (data->forks == NULL)
	{
		//error or free;
		exit(0);
	}
	while (i < data->nop)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	fill_struct(t_data *data, int i, int j)
{
	data->philo[i].id = i + 1;
	data->philo[i].nota = 0;
	data->philo[i].time_to_die = 0;
	data->philo[i].fork.left = i;
	data->philo[i].fork.right = j;
	
}

int	creat_philos(t_data *data)
{
	int i;
	int	j;

	data->philo = malloc(sizeof(t_philo) * (data->nop + 1));
	if (data->philo == NULL)
	{
		//free;
		exit(0);
	}
	i = 0;
	j = 1;
	while (j < data->nop)
	{
		fill_struct(data, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_struct(data, i, j);
	return (1);
}

void creat_threads(t_data *data)
{
	int i;

	i = 0;
	data->philo = malloc(sizeof(pthread_t) * data->nop + 1);
	if (data->forks == NULL)
	{
		//free(data->forks);
		exit(0);
	}
	while (i < data->nop)
	{
		pthread_create(&data->philo[i].thread, NULL, &thread, (void *)data);
		i++;
		usleep(1000);
	}
}

