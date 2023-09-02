/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:36:43 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 14:39:48 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	mysleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (is_dead(philo) == DEATH)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (DEATH);
	}
	ft_printf(GREEN"%d %d is sleeping\n", (int)getime(philo->data), \
	philo->number);
	pthread_mutex_unlock(&philo->data->print_mutex);
	while (getime(philo->data) - philo->last_meal < philo->data->eat + \
	philo->data->sleep)
		usleep(100);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (is_dead(philo) == DEATH)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (DEATH);
	}
	ft_printf(RED"%d %d is thinking\n", (int)getime(philo->data), philo->number);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (E_OK);
}
