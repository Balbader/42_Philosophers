/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:53:04 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:53:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * Checks if the created thread is still running
 * if Yes returns True
 * else will will nullyphy all threads, and free all memory allocated
 * returns False
*/

t_bool	ft_init_threads(pthread_t *philo_threads, pthread_t *philo_monitors,
		t_philo *philosophers, int i)
{
	if (pthread_create(&philo_threads[i], NULL, &ft_dinner, &philosophers[i]) != 0)
	{
		*philosophers[0].is_dinner_over = TRUE;
		while (--i >= 0)
		{
			pthread_join(philo_threads[i], NULL);
			pthread_join(philo_monitors[i], NULL);
		}
		ft_memdel((void **)&philo_threads);
		ft_memdel((void **)&philo_monitors);
		return (FALSE);
	}
	if (!ft_init_threads_monitoring(philo_threads, philo_monitors,
			philosophers, i))
		return (FALSE);
	return (TRUE);
}
