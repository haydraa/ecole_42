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

/*void thread(void *var)
{
	sleep	
}*/

/*void	creat_threads(t_data *data)
{
	pthread_create(&data->philosopher, NULL, )
}*/

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 5)
		error_args();
	else if (check_args(argc,argv) == 0)
		write(2, "Error\nyou_need_numbers\n", 23);
	data.number_of_philosopher = atof(argv[1]);
	printf("%d\n", data.number_of_philosopher);
	data.time_to_die = atof(argv[2]);
	printf("%f\n", data.time_to_die);
	data.time_to_eat = atof(argv[3]);
	printf("%f\n", data.time_to_die);
	data.time_to_sleep = atof(argv[argc - 1]);
	printf("%f\n", data.time_to_sleep);
	//creat_threads(&data);
	return 0;
}
	
