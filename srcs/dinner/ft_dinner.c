/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:32:23 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:32:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * file		:	diner.c
 * function	:	void *diner(void *arg)
*/

void	*ft_diner(void *arg)
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
