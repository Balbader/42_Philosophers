/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:50:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/30 15:30:20 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	clean_mem(t_rules *r)
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
