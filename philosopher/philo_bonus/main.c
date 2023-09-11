/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:55:54 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/08 16:06:45 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->death);
		if (philo->next_meal < ft_get_time())
		{
			ft_print("is dead", DIED, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
		sem_wait(philo->data->death);
		if ((philo->data->notepme != -1)
			&& (philo->data->current_eat >= philo->data->max_eat))
		{
			ft_print("Done", DONE, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	philo->next_meal = ft_get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_print("thinking", 0, philo);
	}
}

void	ft_creat_process(t_semiph *semiph, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < semiph->n_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}

unsigned int	ft_get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	int			i;
	t_semiph	semiph;
	t_philo		*philo;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error argument\n");
		return (1);
	}
	if (ft_check(argv, &semiph) == -1)
	{
		printf("Error inside the argument\n");
		return (1);
	}
	philo = ft_philo_init(&semiph);
	semiph.time_s = ft_get_time();
	ft_creat_semi(&semiph);
	sem_wait(semiph.stop);
	ft_creat_process(&semiph, philo);
	sem_wait(semiph.stop);
	ft_destroy(&semiph, philo);
	return (0);
}
