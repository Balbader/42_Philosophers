/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:32:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:32:34 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_eat(t_philo *philo)
{
	time_t		time;
	time_t		speak_delay;

	pthread_mutex_lock(&philo->forks[philo->fork_left]);
	if (!speak(philo, get_time(), FORK) || philo->nb_forks == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->fork_left]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->forks[philo->fork_right]);
	time = get_time();
	pthread_mutex_lock(philo->is_eating);
	if ((time - philo->last_meal) > philo->time_to_die)
		announce_death(philo, time, DIE);
	else
		speak(philo, time, EAT);
	philo->last_meal = time;
	speak_delay = get_time() - time;
	if (!*philo->is_diner_over && speak_delay < philo->time_to_eat)
		ft_usleep((philo->time_to_eat - speak_delay) * 1000);
	pthread_mutex_unlock(&philo->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->forks[philo->fork_right]);
	pthread_mutex_unlock(philo->is_eating);
	return (!*philo->is_diner_over);
}
