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

int	ft_check_vitals(t_rules *r, int i)
{
	pthread_mutex_lock(&(r->health_check));
	if (ft_time_diff(ft_get_time(), r->philos[i].last_meal)
		> (unsigned long)r->time_to_die)
	{
		r->dead_end = 1;
		pthread_mutex_unlock(&(r->health_check));
		ft_print_state(&(r->philos[i]), r, "died");
		return (1);
	}
	else if (r->x_meal > 0 && r->philos[i].hunger == 1)
	{
		if (r->philos[i].nb_meal >= r->x_meal)
		{
			r->philos[i].hunger = 0;
			pthread_mutex_unlock(&(r->health_check));
			return (2);
		}
		pthread_mutex_unlock(&(r->health_check));
	}
	else
		pthread_mutex_unlock(&(r->health_check));
	return (0);
}
