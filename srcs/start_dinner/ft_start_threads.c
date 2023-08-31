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

t_bool	ft_start_threads(t_dinner *diner_setup, t_philo *philosophers,
		int nb_philo)
{
	int			i;
	time_t		time;

	i = 0;
	time = ft_get_time();
	while (i < nb_philo)
	{
		philosophers[i].last_meal = time;
		philosophers[i].start_time = time;
		if (!ft_init_threads(diner_setup->philo_threads,
				diner_setup->philo_monitors, philosophers, i))
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
