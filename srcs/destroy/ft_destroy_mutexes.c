/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:52:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:52:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * destroy pthread __data
*/

int	ft_destroy_mutexes(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->nb_philo)
	{
		if (!&(config->forks[i]))
			pthread_mutex_destroy(&(config->forks[i]));
		i++;
	}
	if (&(config->printing.__data))
		pthread_mutex_destroy(&(config->printing));
	if (&(config->health_check.__data))
		pthread_mutex_destroy(&(config->health_check));
	if (config)
		free(config);
	return (0);
}
