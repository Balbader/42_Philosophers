/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vitals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:26:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:26:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * . Lock the health_check thread
 * . checks :
 * . 1. if the last meal took more time than time to die:
 * 		-> unlock the thread
 * 		-> print died msg
 * 		-> stop process
 * . 2. if meals tot is greater than 0 && philosopher is hungry:
 * 		-> check if the numbers of meals eaten is >= to tot meals
 * 		-> if yes , philosopher not hungry anymore
 * . Unlock thread
*/
int	ft_check_vitals(t_config *conf, int i)
{
	pthread_mutex_lock(&(conf->health_check));
	if (ft_time_diff(ft_get_time(), conf->philos[i].last_meal)
		> (unsigned long)conf->time_to_die)
	{
		conf->dead_end = 1;
		pthread_mutex_unlock(&(conf->health_check));
		ft_print_state(&(conf->philos[i]), conf, DIED);
		return (1);
	}
	else if (conf->tot_meals > 0 && conf->philos[i].hungry == 1)
	{
		if (conf->philos[i].meal_count >= conf->tot_meals)
		{
			conf->philos[i].hungry = 0;
			pthread_mutex_unlock(&(conf->health_check));
			return (2);
		}
		pthread_mutex_unlock(&(conf->health_check));
	}
	else
		pthread_mutex_unlock(&(conf->health_check));
	return (0);
}
