/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_til_the_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:49:12 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 12:49:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * The loop will keep running until 1 of 2 conditions are met.
 * 1. all philosophers have eaten the expected number of meals
 * 2. a philosopher has died
*/

void	ft_til_the_end(t_config *philosophers, int i, int vitals)
{
	int	all_philos;

	all_philos = 0;
	while (1)
	{
		i = 0;
		if (ft_check_health(philosophers) == 0)
			break ;
		while (i < philosophers->nb_philo)
		{
			vitals = ft_check_vitals(philosophers, i);
			if (vitals == 1)
				break ;
			else if (vitals == 2)
				all_philos++;
			if (all_philos == philosophers->nb_philo)
			{
				pthread_mutex_lock(&(philosophers->health_check));
				philosophers->all_ate = 1;
				pthread_mutex_unlock(&(philosophers->health_check));
			}
			i++;
		}
	}
	usleep(200);
}
