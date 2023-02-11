#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// notepme == number_of_time_each_philosopher_must_eat

typedef struct s_data
{
	pthread_t philosopher;
	int		number_of_philosopher;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	//int notepme;
}			t_data;

void	error_args(void);
void	creat_threads(t_data *data);
int		check_args(int argc, char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
#endif
