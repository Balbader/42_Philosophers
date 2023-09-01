/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:57:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:57:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * starts the simulation
 * returns True if the launch was successful
 * returns False if the initialization of the threads was unsuccessful
*/

t_bool	ft_start_threads(t_dinner *dinner_setup, t_philo *philosophers,
		int nb_philo)
{
	int			i;
	time_t		time;

	i = 0;
	time = ft_get_time();
	while (i < nb_philo)
	{
		philosophers[i].start_time = time;
		philosophers[i].last_meal = time;
		if (!ft_init_threads(dinner_setup->philo_threads,
				dinner_setup->philo_monitors, philosophers, i))
			return (ft_print_err(THREAD_CREATE, NULL, FALSE));
		i += 2;
		if (i % 2 == 0 && i >= nb_philo)
		{
			i = 1;
			ft_usleep(2000);
		}
	}
	return (TRUE);
}
