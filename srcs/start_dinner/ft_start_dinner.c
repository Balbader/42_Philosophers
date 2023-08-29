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

/*
 * file		:	launch_diner.c
 * function	:	t_bool launch_diner
*/

t_bool	ft_start_dinner(t_diner *diner_setup, t_philo *philosophers,
		int nb_philo)
{
	diner_setup->philo_threads = malloc(nb_philo * sizeof(pthread_t));
	diner_setup->philo_monitors = malloc(nb_philo * sizeof(pthread_t));
	if (!diner_setup->philo_threads || !diner_setup->philo_monitors)
	{
		if (diner_setup->philo_threads)
			ft_memdel((void **)&diner_setup->philo_threads);
		if (diner_setup->philo_monitors)
			ft_memdel((void **)&diner_setup->philo_monitors);
		return (ft_print_err(THREAD_ALLOC, NULL, FALSE));
	}
	return (ft_start_threads(diner_setup, philosophers, nb_philo));
}
