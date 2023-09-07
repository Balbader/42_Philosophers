/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:36:54 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <limits.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

static t_bool	eat(t_philo *philo)
{
	time_t		time;
	time_t		speak_delay;

	sem_wait(philo->forks);
	if (!speak(philo, get_time(), FORK) || philo->nb_forks == 1)
	{
		sem_post(philo->forks);
		return (FALSE);
	}
	sem_wait(philo->forks);
	time = get_time();
	sem_wait(philo->is_eating);
	if ((time - philo->last_meal) > philo->time_to_die)
		announce_death(philo, time);
	else
		speak(philo, time, EAT);
	philo->last_meal = time;
	speak_delay = get_time() - time;
	if (!philo->is_diner_over && speak_delay < philo->time_to_eat)
		ft_usleep((philo->time_to_eat - speak_delay) * 1000);
	sem_post(philo->forks);
	sem_post(philo->forks);
	sem_post(philo->is_eating);
	return (!philo->is_diner_over);
}

void	diner(t_philo *philo)
{
	time_t		time;
	time_t		speak_delay;

	while (!philo->is_diner_over && philo->min_nb_meal != 0)
	{
		if (philo->min_nb_meal > 0 && philo->nb_meal >= philo->min_nb_meal)
			ft_usleep(1000);
		if (!eat(philo))
			break ;
		time = get_time();
		if (philo->nb_meal < INT_MAX)
			if (++philo->nb_meal == philo->min_nb_meal)
				sem_post(philo->reached_nb_meal);
		if (!speak(philo, time, SLEEP))
			break ;
		speak_delay = get_time() - time;
		if (!philo->is_diner_over && speak_delay < philo->time_to_sleep)
			ft_usleep((philo->time_to_sleep - speak_delay) * 1000);
		if (!speak(philo, get_time(), THINK))
			break ;
	}
}
