/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:16:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 11:16:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_bool	ft_is_dead(t_philo *philo, time_t time, char *message)
{
	time -= philo->start_time;
	pthread_mutex_lock(philo->is_thinking);
	if (!*philo->is_dinner_over)
	{
		printf("%10lums  %d  %s\n", time, philo->id, message);
		*philo->is_dinner_over = TRUE;
	}
	pthread_mutex_unlock(philo->is_thinking);
	return (FALSE);
}
