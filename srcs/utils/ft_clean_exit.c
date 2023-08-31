/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:14:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 18:14:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_clean_exit(t_dinner *dinner_setup, t_philo *philosophers,
		int nb_philo, int ret_val)
{
	int		i;

	if (dinner_setup->philo_threads)
	{
		i = 0;
		while (i < nb_philo)
		{
			pthread_join(dinner_setup->philo_threads[i], NULL);
			pthread_join(dinner_setup->philo_monitors[i++], NULL);
		}
	}
	ft_clean_mutexes(&dinner_setup->mutexes, nb_philo);
	if (dinner_setup->philo_threads)
		free(dinner_setup->philo_threads);
	if (dinner_setup->philo_monitors)
		free(dinner_setup->philo_monitors);
	if (philosophers)
		free(philosophers);
	return (ret_val);
}
