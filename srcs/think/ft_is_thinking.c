/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:16:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 11:16:30 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * file		:	speak.c
 * function	:	t_bool announce_death
*/

t_bool	ft_is_thinking(t_philo *philo, time_t time, char *message)
{
	if (ft_strcmp(MIN_NB_MEAL, msg)
		&& (time - philo->last_meal) > philo->time_to_die)
		return (FALSE);
	time -= philo->start_time;
	pthread_mutex_lock(philo->is_thinking);
	if (!ft_strcmp(MIN_NB_MEAL, message) && !*philo->is_diner_over)
	{
		*philo->is_diner_over = TRUE;
		printf("%s %d %.*s\n", message,
			philo->min_nb_meal, 5 - (philo->min_nb_meal <= 1), "times");
	}
	else if (!ft_strcmp(EAT, msg) && !*philo->is_diner_over)
		printf("%10lums  %d  %s\n%10lums  %d  %s\n", time, philo->id, FORK,
			time, philo->id, message);
	else if (!*philo->is_diner_over)
		printf("%10lums  %d  %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->is_thinking);
	return (!*philo->is_diner_over);
}
