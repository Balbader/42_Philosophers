/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_threads_monitoring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:40:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:40:28 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * file		:	launch_diner.c
 * function	:	static t_bool create_monitor_threads
*/

t_bool	ft_init_threads_monitoring(pthread_t *philo_threads,
			pthread_t *philo_monitor, t_philo *philosophers, int i)
{
	if (pthread_create(&philo_monitors[i], NULL,
			&monitor_philo, &philosophers[i]) != 0)
	{
		*philosophers[0].is_diner_over = TRUE;
		pthread_join(philo_threads[i], NULL);
		while (--i >= 0)
		{
			pthread_join(philo_threads[i], NULL);
			pthread_join(philo_monitors[i], NULL);
		}
		ft_memdel((void **)&philo_threads);
		ft_memdel((void **)&philo_monitors);
		return (FALSE);
	}
	return (TRUE);
}
