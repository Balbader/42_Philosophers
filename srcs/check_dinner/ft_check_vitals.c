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
 * 
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
	else if (conf->x_meal > 0 && conf->philos[i].hunger == 1)
	{
		if (conf->philos[i].nb_meal >= conf->x_meal)
		{
			conf->philos[i].hunger = 0;
			pthread_mutex_unlock(&(conf->health_check));
			return (2);
		}
		pthread_mutex_unlock(&(conf->health_check));
	}
	else
		pthread_mutex_unlock(&(conf->health_check));
	return (0);
}
