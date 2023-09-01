/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:16:33 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 11:25:34 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_mutex);
	if (philo->data->death[0] == DEATH)
	{
		pthread_mutex_unlock(philo->data->death_mutex);
		return (DEATH);
	}
	pthread_mutex_unlock(philo->data->death_mutex);
	return (E_OK);
}
