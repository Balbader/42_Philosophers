/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:56:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 11:56:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * file		:	init.c
 * function	:	t_bool init_mutexes
*/

t_bool	ft_init_mutexes(t_mutexes *mutexes, int nb_philo)
{
	if (pthread_mutex_init(&mutexes->is_speaking, NULL) != 0)
		return (print_error(MUTEX_INIT, NULL, FALSE));
	mutexes->forks = malloc(nb_philo * sizeof(pthread_mutex_t));
	mutexes->is_eating = malloc(nb_philo * sizeof(pthread_mutex_t));
	if (!mutexes->forks || !mutexes->is_eating)
	{
		pthread_mutex_destroy(&mutexes->is_speaking);
		if (mutexes->forks)
			free(mutexes->forks);
		if (mutexes->is_eating)
			free(mutexes->is_eating);
		return (print_error(MUTEX_ALLOC, NULL, FALSE));
	}
	if (!init_array_mutexes(mutexes->forks, mutexes->is_eating, nb_philo))
	{
		pthread_mutex_destroy(&mutexes->is_speaking);
		free(mutexes->forks);
		free(mutexes->is_eating);
		return (print_error(MUTEX_INIT, NULL, FALSE));
	}
	return (TRUE);
}
