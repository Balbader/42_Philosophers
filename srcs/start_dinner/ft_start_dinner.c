/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:57:57 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:57:59 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_bool	ft_start_dinner(t_dinner *dinner_setup, t_philo *philosophers,
		int nb_philo)
{
	dinner_setup->philo_threads = malloc(nb_philo * sizeof(pthread_t));
	dinner_setup->philo_monitors = malloc(nb_philo * sizeof(pthread_t));
	if (!dinner_setup->philo_threads || !dinner_setup->philo_monitors)
	{
		if (dinner_setup->philo_threads)
			ft_memdel((void **)&dinner_setup->philo_threads);
		if (dinner_setup->philo_monitors)
			ft_memdel((void **)&dinner_setup->philo_monitors);
		return (ft_print_err(THREAD_ALLOC, NULL, FALSE));
	}
	return (ft_start_threads(dinner_setup, philosophers, nb_philo));
}
