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

#include "../../inc/philo.h"

/*
 * write function that checks if philo->id is pair do : 
 *
	pthread_mutex_lock(&philo->forks[philo->fork_left]);
	if (!ft_is_thinking(philo, ft_get_time(), FORK) || philo->nb_forks == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->fork_left]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->forks[philo->fork_right]);
	
	else do:
	pthread_mutex_lock(&philo->forks[philo->fork_right]);
	if (!ft_is_thinking(philo, ft_get_time(), FORK) || philo->nb_forks == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->fork_right]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->forks[philo->fork_left]);
*/

t_bool	ft_eat(t_philo *philo)
{
	time_t		time;
	time_t		think_delay;

	pthread_mutex_lock(&philo->forks[philo->fork_left]);
	if (!ft_print_state(philo, ft_get_time(), FORK) || philo->nb_forks == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->fork_left]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->forks[philo->fork_right]);
	pthread_mutex_lock(philo->is_eating);
	time = ft_get_time();
	if ((time - philo->last_meal) > philo->time_to_die)
		ft_is_dead(philo, time, DIE);
	else
		ft_print_state(philo, time, EAT);
	philo->last_meal = time;
	think_delay = ft_get_time() - time;
	if (!*philo->is_dinner_over && think_delay < philo->time_to_eat)
		ft_usleep((philo->time_to_eat - think_delay) * 1000);
	pthread_mutex_unlock(&philo->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->forks[philo->fork_right]);
	pthread_mutex_unlock(philo->is_eating);
	return (!*philo->is_dinner_over);
}
