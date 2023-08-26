/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:23:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 16:23:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * file		:	monitor_diner.c
 * function	:	void monitor_philo
*/

void	*ft_check_philosopher(void *arg)
{
	t_philo		*philo;
	time_t		time;

	philo = (t_philo *)arg;
	while (!*philo->is_diner_over)
	{
		pthread_mutex_lock(philo->is_eating);
		time = get_time();
		if (!*philo->is_diner_over
			&& (time - philo->last_meal) > philo->time_to_die)
		{
			if (philo->min_nb_meal >= 0 && philo->nb_meal == philo->min_nb_meal)
				ft_usleep(1000);
			if (!*philo->is_diner_over)
				announce_death(philo, time, DIE);
		}
		pthread_mutex_unlock(philo->is_eating);
		if (!*philo->is_diner_over)
			ft_usleep(1000);
	}
	return (arg);
}
