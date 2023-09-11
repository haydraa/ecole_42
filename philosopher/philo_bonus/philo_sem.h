/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:55:59 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/04 15:56:00 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SEM_H
# define PHILO_SEM_H

# include <semaphore.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <string.h>

# define DIED 7
# define DONE 8

typedef struct s_semiph
{
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*protect;
	sem_t			*stop;
	unsigned int	time_s;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				notepme;
	int				max_eat;
	int				current_eat;
}					t_semiph;

typedef struct s_philo
{
	t_semiph		*data;
	pid_t			pid;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				dead;
	int				notepme;
}					t_philo;

unsigned int	ft_get_time(void);
void			ft_print(char *string, int id, t_philo *philo);
t_philo			*ft_philo_init(t_semiph *semiph);
void			ft_init_philo(t_semiph *semiph, t_philo *philo, int i);
void			ft_destroy(t_semiph *semiph, t_philo *philo);
void			ft_creat_semi(t_semiph *semiph);
int				ft_check(char **argv, t_semiph *semiph);
int				ft_set_data(t_semiph *semiph, int num, int i);
void			ft_take_fork(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);

#endif
