/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:29:34 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/01 11:29:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_bool	ft_print_state(t_philo *philo, time_t time, char *message)
{
	if (ft_strcmp(MIN_NB_MEAL, message)
		&& (time - philo->last_meal) > philo->time_to_die)
		return (FALSE);
	pthread_mutex_lock(philo->is_thinking);
	time -= philo->start_time;
	if (!ft_strcmp(MIN_NB_MEAL, message) && !*philo->is_dinner_over)
	{
		*philo->is_dinner_over = TRUE;
		printf("%s %d %.*s\n", message,
			philo->min_nb_meal, 5 - (philo->min_nb_meal <= 1), "times");
	}
	else if (!ft_strcmp(EAT, message) && !*philo->is_dinner_over)
		printf("%10lums  %d  %s\n%10lums  %d  %s\n", time, philo->id, FORK,
			time, philo->id, message);
	else if (!*philo->is_dinner_over)
		printf("%10lums  %d  %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->is_thinking);
	return (!*philo->is_dinner_over);
}
