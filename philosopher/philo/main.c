#include "philo.h"

void error_args(void)
{
	write(2, "Error_args\n", 11);
	write(2, "the args are:\n", 14);
	write(2, "number_of_philosophers ", 24);
	write(2, "time_to_die ", 12);
	write(2, "time_to_eat ", 12);
	write(2, "time_to_sleep\n", 14);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < argc)
	{
		while (argv[j])
		{
			if(ft_isdigit(argv[i][j]) == 0)
				return 1;
			if (argv[i][j] == '.' || argv[i][j] == ',')
				j++;
			j++;
		}
		i++;
	}
	return 0;
}

void thread(pthread_t *philo, pthread_mutex_t *fork, int index)
{
	if (index == 0)
	{

	}
}

void	creat_threads(t_data *data)
{
	pthread_t	philo[data->nop];
	pthread_mutex_t fork[data->nop];
	int i;
	int k;

	i = 0;
	while(i < data->nop);
	{
		k = pthread_mutex_init(&fork[i], NULL);
		if (k == -1)
		{
			printf("Mutex initialization faild\n");
			exit(1);
		}
	}
	i = 0;
	while (i < data->nop);
	{
		k = pthread_create(&philo, NULL, thread(i),(int *i));
		if (!k)
		{
			printf("philo has did befor he even born :') \n");
			exit(1);
		}
		i++;
	}
	

}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 5)
		error_args();
	else if (check_args(argc,argv) == 0)
		write(2, "Error\nyou_need_numbers\n", 23);
	data.nop = ft_atoi(argv[1]);
	printf("%d\n", data.number_of_philosopher);
	data.time_to_die = ft_atoi(argv[2]);
	printf("%f\n", data.time_to_die);
	data.time_to_eat = ft_atoi(argv[3]);
	printf("%f\n", data.time_to_die);
	data.time_to_sleep = ft_atoi(argv[argc - 1]);
	printf("%f\n", data.time_to_sleep);
	creat_threads(philo, fork, &data);
	return 0;
}
	
