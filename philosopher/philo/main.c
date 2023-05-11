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

void forks_threads(t_data *data)
{
	int i;

	i = 0;
	creat_forks(data);
	creat_threads(data);

	while (i < data->nop)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 6)
	{
		printf("Erorr arguments\n");
		return (0);
	}
	check_args(argc, argv);
	data.nop = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.notepme = ft_atoi(argv[5]);
	forks_threads(&data);
}
