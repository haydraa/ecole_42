#include "philo.h"

void check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("you have somthing other then numbers !!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int		one_philo_exuction(t_data *data)
{
	if (pthread_mutex_init(&data->write, NULL) != 0)
	{
		free(data->forks);
		return (1);
	}
	data->t0 = get_time();
	ft_printf(data, 1 , "has take a fork\n");
	exec_action(data->time_to_die);
	ft_printf(data, 1., "died\n");
	free(data->forks);
	free(data->philo);
	return (0);
}

void forks_threads(t_data *data)
{
	int i;

	i = 0;
	if (creat_philos(data) == 1)
		exit(1);
	if (creat_forks(data) == 1)
		exit(1);
	if (data->nop == 1)
	{
		data->dead = 0;
		if (one_philo_exuction(data) == 0)
			return ;
	}
	if(creat_threads(data) == 1)
	{
		free(data->forks);
		exit(1);
	}
	if (destroy_threads(data) == 1)
		clear_error(data);
	free(data->forks);
	free(data->philo);

}

int main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 7)
	{
		printf("Erorr arguments\n");
		return (0);
	}
	check_args(argc, argv);
	data.nop = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (check_numbers(&data) == 1)
		return (0);
	if (argc == 6)
		data.notepme = ft_atoi(argv[5]);
	else
		data.notepme = 0;
	forks_threads(&data);
	return (0);
}
