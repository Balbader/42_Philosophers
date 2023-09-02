/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:00:02 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:00:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			ft_putstr_fd(MUTEX_ERR, 2);
		i++;
	}
	if (pthread_mutex_init(&(rules->printing), NULL))
		ft_putstr_fd(MUTEX_ERR, 2);
	if (pthread_mutex_init(&(rules->health_check), NULL))
		ft_putstr_fd(MUTEX_ERR, 2);
	return (0);
}
