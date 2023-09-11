/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:55:45 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/04 15:55:47 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	ft_creat_semi(t_semiph *semiph)
{
	sem_unlink("death");
	sem_unlink("protect");
	sem_unlink("message");
	sem_unlink("stop");
	sem_unlink("forks");
	semiph->death = sem_open("death", O_CREAT, 0600, 1);
	semiph->message = sem_open("message", O_CREAT, 0600, 1);
	semiph->stop = sem_open("stop", O_CREAT, 0600, 1);
	semiph->protect = sem_open("protect", O_CREAT, 0600, 1);
	semiph->forks = sem_open("forks", O_CREAT, 0600, semiph->n_philo);
	if (semiph->death ==  SEM_FAILED || semiph->message ==  SEM_FAILED 
				|| semiph->stop ==  SEM_FAILED || semiph->protect ==  SEM_FAILED
				|| semiph->forks ==  SEM_FAILED)
	{
		printf("Semiph alloction failed\n");
		exit(1);
	}
}

void	ft_destroy(t_semiph *semiph, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < semiph->n_philo)
		kill(philo[i++].pid, SIGKILL);
	sem_close(semiph->death);
	sem_close(semiph->message);
	sem_close(semiph->stop);
	sem_close(semiph->protect);
	sem_close(semiph->forks);
	free(philo);
}

void	ft_init_philo(t_semiph *semiph, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].dead = 0;
	philo[i].data = semiph;
	philo[i].pid = -1;
	if (semiph->notepme == -1)
			philo[i].notepme = -1;
	else
			philo[i].notepme = semiph->notepme;
}

t_philo	*ft_philo_init(t_semiph *semiph)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * semiph->n_philo);
	semiph->death = NULL;
	semiph->stop = NULL;
	semiph->protect = NULL;
	semiph->message = NULL;
	semiph->forks = NULL;
	while (++i < semiph->n_philo)
		ft_init_philo(semiph, philo, i);
	return (philo);
}

void	ft_print(char *string, int id, t_philo *philo)
{
	unsigned int	time;

	time = ft_get_time() - philo->data->time_s;
	sem_wait(philo->data->message);
	if (id == DIED)
		printf("%u %d has died\n", time, philo->index + 1);
	else if (id == DONE)
		printf("dinner is over :D\n");
	else if (id == 0)
		printf("%u %d %s\n", time, philo->index + 1, string);
	if (id != DIED)
		sem_post(philo->data->message);
}
