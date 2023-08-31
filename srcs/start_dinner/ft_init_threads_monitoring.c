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

#include "../../inc/philo.h"

t_bool	ft_init_threads_monitoring(pthread_t *philo_threads,
			pthread_t *philo_monitors, t_philo *philosophers, int i)
{
	if (pthread_create(&philo_monitors[i], NULL,
			&ft_check_philosopher, &philosophers[i]) != 0)
	{
		*philosophers[0].is_dinner_over = TRUE;
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
