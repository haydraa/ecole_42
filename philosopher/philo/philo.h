#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/time.h>


// notep.me == number_of_time_each_philosopher_must_eat
//nop == number_of_philosopher
//nota == number_of_time_ate

typedef struct s_fork
{
		int left;
		int	right;
}			t_fork;

typedef struct s_philo
{
	int	id;
	int nota;
	long long time_to_die;
	t_fork	fork;
	pthread_t thread;
}	t_philo;

typedef struct s_data
{
	int		dead;
	int		eating;
	int		sleeping;
	int		thinking;

	int		left_fork;
	int		right_fork;	
	
	int		id;
	
	int		nop;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		notepme;
	
	t_philo	*philo;	

	pthread_mutex_t *forks;

}			t_data;

void	*thread(void *arg);
void	creat_threads(t_data *data);
void	creat_forks(t_data *data);
void	check_args(int argc, char **argv);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
#endif
