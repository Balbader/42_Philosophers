/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mutexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:14:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 18:14:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * Destroy all mutexes and free allocated memory
*/
void	ft_clean_mutexes(t_mutexes *mutexes, int nb_philo)
{
	int		i;

	if (pthread_mutex_destroy(&mutexes->is_thinking) != 0)
		ft_print_err(MUTEX_DESTROY, NULL, ERROR);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_destroy(&mutexes->forks[i]) != 0)
			ft_print_err(MUTEX_DESTROY, NULL, ERROR);
		if (pthread_mutex_destroy(&mutexes->is_eating[i++]) != 0)
			ft_print_err(MUTEX_DESTROY, NULL, ERROR);
	}
	free(mutexes->forks);
	free(mutexes->is_eating);
}
