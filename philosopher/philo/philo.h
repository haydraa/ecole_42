/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:48:35 by jghribi           #+#    #+#             */
/*   Updated: 2023/08/15 11:48:36 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>

//Necrosyne == death follower
// notepme == number_of_time_each_philosopher_must_eat
//nop == number_of_philosopher
//nota == number_of_time_ate

typedef struct s_fork
{
	int	left;
	int	right;
}		t_fork;

typedef struct s_philo
{
	int				id;
	int				nota;
	long long		time_to_die;
	t_fork			fork;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}		t_philo;

typedef struct s_data
{
	int				n_thread;
	int				dead;
	long long		t0;
	int				id;
	int				nop;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				notepme;	
	t_philo			*philo;	
	pthread_t		necrosyne;
	pthread_mutex_t	protect;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}			t_data;

void		clear_error(t_data *data);
int			creat_philos(t_data *data);
int			join_thread(t_data *data);
int			destroy_threads(t_data *data);
void		exec_action(long long time);
long long	delta_time(long long time);
long long	get_time(void);
void		*routine(void *arg);
int			ft_printf(t_data *data, int id, char *movment);
int			creat_threads(t_data *data);
int			creat_forks(t_data *data);
void		check_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
void		fill_struct(t_data *data, int i, int j);
int			philo_eat(t_data *data, int i);
int			philo_sleep(t_data *data, int i);
int			philo_think(t_data *data, int i);
int			routine_execute(t_data *data, int i);
int			philo_is_dead(t_data *data, int *i);
int			drop_function(t_data *data, int i);
void		*checker(void *args);
int			routine_execute(t_data *data, int i);
int			ft_isdigit(int c);
int			check_numbers(t_data *data);
int			error(void);
void		unlock_fork(t_data *data);
int			error_handel(t_data *data, int key, int i);

#endif
