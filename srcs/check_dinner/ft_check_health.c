/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_health.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:26:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:26:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * Locks the health_check thread is order to check if either all philosophers
 * have eaten or if one has died.
*/

int	ft_check_health(t_config *philo)
{
	int	i;

	pthread_mutex_lock(&(philo->health_check));
	if (philo->all_ate || philo->dead_end)
		i = 0;
	else
		i = 1;
	pthread_mutex_unlock(&(philo->health_check));
	return (i);
}
