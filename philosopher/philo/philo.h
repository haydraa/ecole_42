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
typedef struct s_data
{
	int		*ph_tab;
	int		nop;
	int		eating;
	int		sleeping;
	int		thinking;
	time_t	tv_sec;
	suseconds_t tv_usec; 
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	//int notepme;
}			t_data;

void	thread(void *arg);
void	error_args(void);
void	creat_threads(t_data *philo);
int		check_args(int argc, char **argv);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
#endif
