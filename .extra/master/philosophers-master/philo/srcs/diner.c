/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:36:56 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <limits.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

static t_bool	eat(t_philo *philo)
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

void	*diner(void *arg)
{
	t_philo			*philo;
	time_t			time;
	time_t			speak_delay;

	philo = (t_philo *)arg;
	while (!*philo->is_diner_over && philo->min_nb_meal != 0)
	{
		if (philo->min_nb_meal > 0 && philo->nb_meal >= philo->min_nb_meal)
			ft_usleep(1000);
		if (!eat(philo))
			break ;
		time = get_time();
		if (philo->nb_meal < INT_MAX)
			philo->nb_meal++;
		if (!speak(philo, time, SLEEP))
			break ;
		speak_delay = get_time() - time;
		if (!*philo->is_diner_over && speak_delay < philo->time_to_sleep)
			ft_usleep((philo->time_to_sleep - speak_delay) * 1000);
		if (!speak(philo, get_time(), THINK))
			break ;
	}
	return (arg);
}
