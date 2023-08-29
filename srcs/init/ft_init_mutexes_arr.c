/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexes_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:51:46 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 11:51:47 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * file		:	init.c
 * function	:	static t_bool init_array_mutexes
*/

t_bool	ft_init_mutexes_arr(pthread_mutex_t *forks, pthread_mutex_t *is_eating,
		int nb_philo)
{
	int		i;
	int		forks_error;
	int		is_eating_error;

	i = 0;
	while (i < nb_philo)
	{
		forks_error = pthread_mutex_init(&forks[i], NULL);
		is_eating_error = pthread_mutex_init(&is_eating[i], NULL);
		if (forks_error || is_eating_error)
		{
			if (!forks_error)
				pthread_mutex_destroy(&forks[i]);
			if (!is_eating_error)
				pthread_mutex_destroy(&is_eating[i]);
			while (--i >= 0)
			{
				pthread_mutex_destroy(&forks[i]);
				pthread_mutex_destroy(&is_eating[i]);
			}
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
