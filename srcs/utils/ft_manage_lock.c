/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_lock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:36:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/01 14:37:00 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_manage_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->is_thinking);
	if (!*philo->is_dinner_over)
	{
		pthread_mutex_unlock(philo->is_thinking);
		return (0);
	}
	pthread_mutex_unlock(philo->is_thinking);
	return (1);
}
