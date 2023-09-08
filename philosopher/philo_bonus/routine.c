/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:56:04 by jghribi           #+#    #+#             */
/*   Updated: 2023/09/04 15:56:05 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print("has taken a fork", 0, philo);
	sem_wait(philo->data->forks);
	ft_print("has taken a fork", 0, philo);
}

void	ft_eat(t_philo *philo)
{
	ft_print("is eating", 0, philo);
	if (philo->data->notepme != -1)
		philo->data->current_eat++;
	usleep(philo->data->time_to_eat * 1000);
	philo->eating_time = ft_get_time();
	philo->next_meal = philo->eating_time
		+ (unsigned int)philo->data->time_to_die;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_print("is sleeping", 0, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
