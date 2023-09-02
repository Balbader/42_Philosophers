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

int	ft_destroy_mutexes(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->nb_philo)
	{
		if (!&(r->forks[i]))
			pthread_mutex_destroy(&(r->forks[i]));
		i++;
	}
	if (&(r->printing.__data))
		pthread_mutex_destroy(&(r->printing));
	if (&(r->health_check.__data))
		pthread_mutex_destroy(&(r->health_check));
	if (r)
		free(r);
	return (0);
}
