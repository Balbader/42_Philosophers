/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:44:45 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:44:46 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_is_eating(t_config *conf, t_philo *philo)
{
	pthread_mutex_lock(&(conf->health_check));
	philo->last_meal = ft_get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&(conf->health_check));
	ft_print_state(philo, conf, EATING);
	ft_usleep(conf->time_to_eat);
}
