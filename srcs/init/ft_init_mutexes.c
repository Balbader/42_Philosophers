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

#include "../../inc/philo.h"

/*
 * Allocates memory and initializes fork mutexes
 * returns True is successful
 * if unsuccessful, destroys mutexes and free allocated memory / returns False
 */

t_bool	ft_init_mutexes(t_mutexes *mutexes, int nb_philo)
{
	if (pthread_mutex_init(&mutexes->is_thinking, NULL) != 0)
		return (ft_print_err(MUTEX_INIT, NULL, FALSE));
	mutexes->forks = malloc(nb_philo * sizeof(pthread_mutex_t));
	mutexes->is_eating = malloc(nb_philo * sizeof(pthread_mutex_t));
	if (!mutexes->forks || !mutexes->is_eating)
	{
		pthread_mutex_destroy(&mutexes->is_thinking);
		if (mutexes->forks)
			free(mutexes->forks);
		if (mutexes->is_eating)
			free(mutexes->is_eating);
		return (ft_print_err(MUTEX_ALLOC, NULL, FALSE));
	}
	if (!ft_init_mutexes_arr(mutexes->forks, mutexes->is_eating, nb_philo))
	{
		pthread_mutex_destroy(&mutexes->is_thinking);
		free(mutexes->forks);
		free(mutexes->is_eating);
		return (ft_print_err(MUTEX_INIT, NULL, FALSE));
	}
	return (TRUE);
}
